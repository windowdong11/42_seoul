// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
// /*   Updated: 2023/06/21 14:50:57 by dowon            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <lsan_stats.h>
// #include <lsan_internals.h>
#include "./ptr_manager/ptr_manager.h"

#include "utils/colors.h"
#include "mlx_utils/mlx_utils.h"
#include "fdf_struct/fdf_struct.h"
#include "utils/angle.h"
#include "utils_3d/utils_3d.h"
#include "fdf_obj/fdf_obj.h"
#include "test/test.h"
#include "hooks/hooks.h"
#include "exception/exception.h"
#include <d_list.h>
#include <libft.h>
#include <MLX42/MLX42.h>
#include <smart_ptr.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ft_printf.h>

// Print the window width and height.
static void	ft_hook(void *param)
{
	t_fdf*const	fdf = param;

	if (fdf->is_updated == fdf_rendered)
		return ;
	ft_memset(fdf->img->pixels, 0,
		fdf->img->width * fdf->img->height * sizeof(int));
	fdf_proj(fdf);
	draw8way(fdf->img);
	fdf->is_updated = fdf_rendered;
}

/* t_quaternion	quat(float angle, t_vector3 v)
{
	t_quaternion	q;

	float s = sin(angle * 0.5f);
	q.w = cos(angle * 0.5f);
	q.x = v.x * s;
	q.y = v.y * s;
	q.z = v.z * s;
	return (q);
} */

#include <fcntl.h>
#include <get_next_line.h>

/*
@param str string to convert to rgba
@param color converted result
@return [RETURNS 0] : success. If return value is not zero, it has error \n
@return [RETURNS 1] : error \n
*/
int	mlx_parse_hex_rgba(const char *str, t_rgba *color)
{
	const size_t	len = ft_strlen(str);

	if (len <= 2 || 8 < len || !ft_starts_with(str, "0x"))
		return (1);
	str += 2;
	*color = 0;
	while (*str != '\0')
	{
		*color *= 16;
		if ('0' <= *str && *str <= '9')
			*color += *str - '0';
		else if ('a' <= *str && *str <= 'f')
			*color += *str + 10 - 'a';
		else if ('A' <= *str && *str <= 'F')
			*color += *str + 10 - 'A';
		else
			return (1);
		++str;
	}
	*color = *color << 8 | 255;
	return (0);
}

int	parse_node(char *str, t_color_point *point)
{
	char	**words;
	int		z;

	if (ft_strchr(str, ',') != NULL)
	{
		words = ft_split(str, ',');
		if (words == NULL)
			return (1);
		if (words[0] == NULL || words[1] == NULL || words[2] != NULL
			|| (ft_parse_int(words[0], &z)
				|| mlx_parse_hex_rgba(words[1], &point->color)))
		{
			ft_free_split(words, words);
			return (1);
		}
		point->point.z = z * 5;
		ft_free_split(words, words);
	}
	else
	{
		if (ft_parse_int(str, &z))
			return (1);
		point->point.z = z * 5;
		point->color = my_mlx_rgba(0, 0, 0, 0xff);
	}
	return (0);
}

typedef struct s_map_data
{
	t_d_list	*nodes;
	int			x;
	int			y;
}	t_map_data;

/* 기울기가 (기울기가 양수인 직선에 대해서)
1보다 작으면, x를 1씩 증가시키면서 y를 올릴지 말지 판단해야함.
y를 증가시키면서 x를 올릴지 말지 판단하면, x가 2칸 이상 뛸 수 있음 (->선이 끊어짐)
1보다 크면, 반대로  y증가 x올릴까말까 판단

f(x)는 x에 대한 직선의 방정식
f`(y)는 y에 대한 직선의 방정식
px는 이전 x의 정수 좌표
py는 이전 y의 정수 좌표
결국 x를 증가시키면서
f(x) - py > 1/2를 판단하나
f`(y) - px > 1/2를 판단하나
이렇게 식이 두개로 갈라지는데 */
void set_point_xy(t_color_point *point, int x, int y)
{
	point->point.x = x * 10;
	point->point.y = y * 10;
}

int	parse_line(char *line, t_map_data *map, int linenumber)
{
	char	**splitted;
	int		count;

	count = 0;
	splitted = ft_split(line, ' ');
	if (splitted == NULL)
		return (1);
	while (splitted[count] != NULL)
	{
		if (smart_new_next(ptr_manager(), map->nodes,
				malloc(sizeof(t_color_point)), free) == NULL
			|| parse_node(splitted[count], (t_color_point *)map->nodes->next->value))
		{
			ft_free_split(splitted, splitted + count);
			return (1);
		}
		set_point_xy(map->nodes->next->value, count, linenumber);
		free(splitted[count]);
		count++;
	}
	free(splitted);
	if (count == 0)
		return (1);
	if (map->x == -1)
		map->x = count;
	else if (map->x != count)
		return (1);
	return (0);
}

void	delete_t_map_data(void *ptr)
{
	t_map_data*const	data = ptr;

	if (ptr != NULL)
		smart_free(ptr_manager(), data->nodes);
	free(data);
}

void remove_endl(char *str)
{
	while (*str != '\n')
		++str;
	if (*str == '\n')
		*str = '\0';
}

t_map_data	parse_map(int fd)
{
	char		*line;
	int			is_last;
	t_map_data	map;

	map.nodes = smart_new_d_list(ptr_manager(), NULL, NULL);
	map.x = -1;
	map.y = 0;
	is_last = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (is_last && line != NULL)
			ft_error();
		if (line == NULL)
			break ;
		remove_endl(line);
		is_last = ft_strlen(line) == 0;
		if (is_last)
			continue;
		if (parse_line(line, &map, map.y))
			ft_error();
		++map.y;
		free(line);
	}
	map.nodes = map.nodes->next;
	smart_free(ptr_manager(), map.nodes->prev);
	return (map);
}

void	connect(t_fdf_obj *obj, int idx, int x, int y, int nx, int ny)
{
	obj->edge[idx][0] = obj->node + obj->width_x * y + x;
	obj->edge[idx][1] = obj->node + obj->width_x * ny + nx;
}

t_fdf_obj	*map_data_to_obj(t_map_data map)
{
	t_fdf_obj*const	obj = new_obj(map.x * map.y,
			((map.x - 1) * map.y) + ((map.y - 1) * map.x));
	t_d_list		*del_node;
	size_t			idx;

	if (obj == NULL)
		ft_error();
	idx = 0;
	obj->width_x = map.x;
	obj->height_y = map.y;
	while (map.nodes != NULL)
	{
		obj->node[idx].point = ((t_color_point *)map.nodes->value)->point;
		obj->node[idx].color = ((t_color_point *)map.nodes->value)->color;
		++idx;
		del_node = map.nodes;
		map.nodes = map.nodes->next;
		smart_free(ptr_manager(), del_node);
	}
	idx = 0;
	for (int y = 0; y < map.y; ++y) {
		for (int x = 0; x < map.x; ++x) {
			if (x + 1 != map.x)
			{
				connect(obj, idx, x, y, x + 1, y);
				++idx;
			}
			if (y + 1 != map.y)
			{
				connect(obj, idx, x, y, x, y + 1);
				++idx;
			}
		}
	}
	return (obj);
}

int	validate_filename(const char *filename)
{
	if (ft_strlen(filename) < 4 || !ft_ends_with(filename, ".fdf"))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	// __lsan_trackMemory = true;
	// smart_init(ptr_manager());
	int			fd;
	t_fdf*const	fdf = new_fdf(1920, 1080, "fdf", true);

	vector3(&fdf->position, 100.0, 100.0, 100.0);
	if (argc != 2 || !validate_filename(argv[1])) {
		mlx_terminate(fdf->mlx);
		ft_error();
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		mlx_terminate(fdf->mlx);
		ft_error();
	}
	fdf->obj = map_data_to_obj(parse_map(fd));
	ft_printf("parsed\n");
	close(fd);
	fdf->tmp = dup_fdf_obj(fdf->obj);
	// fdf->scale = (t_vector3){
	// 	fdf->img->width * 80 / fdf->obj->width_x,
	// 	fdf->img->height * 80 / fdf->obj->height_y,
	// 	10
	// };
	// fdf->obj = new_obj(4, 4);
	// fdf->obj->node[0].point = (t_point3d){0, 0, 0};
	// fdf->obj->node[1].point = (t_point3d){100, 0, 0};
	// fdf->obj->node[2].point = (t_point3d){0, 100, 0};
	// fdf->obj->node[3].point = (t_point3d){100, 100, 0};
	// fdf->obj->edge[0][0] = fdf->obj->node + 0;
	// fdf->obj->edge[0][1] = fdf->obj->node + 1;
	// fdf->obj->edge[1][0] = fdf->obj->node + 0;
	// fdf->obj->edge[1][1] = fdf->obj->node + 2;
	// fdf->obj->edge[2][0] = fdf->obj->node + 1;
	// fdf->obj->edge[2][1] = fdf->obj->node + 3;
	// fdf->obj->edge[3][0] = fdf->obj->node + 2;
	// fdf->obj->edge[3][1] = fdf->obj->node + 3;
	fdf->is_updated = fdf_changed;
	mlx_key_hook(fdf->mlx, key_hook, fdf);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	// __lsan_printStats();
    // __lsan_printFragmentationStats();
	smart_exit(ptr_manager(), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

// int main()
// {
//     void * pointer = malloc(150);
// 	(void)pointer;
// 	exit(0);
// }
