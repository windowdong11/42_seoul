/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 21:24:18 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Print the window width and height.
static void	ft_hook(void *param)
{
	t_fdf*const	fdf = param;

	if (fdf->is_updated == 0)
		return ;
	ft_memset(fdf->img->pixels, 255,
		fdf->img->width * fdf->img->height * sizeof(int));
	printf("angle : %f %f %f\n", anglef(fdf->rad.x), anglef(fdf->rad.y), anglef(fdf->rad.z));
	fdf_proj(fdf);
	fdf->is_updated = 0;
}

t_fdf_obj	*cube()
{
	t_fdf_obj*const obj = new_obj(8, 12);
	if (obj == NULL)
		return (NULL);
	obj->node[0] = (t_color_point){{{-25, -25, -25},my_mlx_rgba(255, 0, 0, 255)}};
	obj->node[1] = (t_color_point){{{25, -25, -25},my_mlx_rgba(0, 255, 0, 255)}};
	obj->node[2] = (t_color_point){{{25, 25, -25},my_mlx_rgba(0, 0, 255, 255)}};
	obj->node[3] = (t_color_point){{{-25, 25, -25},my_mlx_rgba(0, 255, 0, 255)}};
	obj->node[4] = (t_color_point){{{-25, -25, 25},my_mlx_rgba(0, 255, 0, 255)}};
	obj->node[5] = (t_color_point){{{25, -25, 25},my_mlx_rgba(0, 255, 0, 255)}};
	obj->node[6] = (t_color_point){{{25, 25, 25},my_mlx_rgba(0, 255, 0, 255)}};
	obj->node[7] = (t_color_point){{{-25, 25, 25},my_mlx_rgba(0, 255, 0, 255)}};
	obj->edge[0][0] = &obj->node[0];
	obj->edge[0][1] = &obj->node[1];
	obj->edge[1][0] = &obj->node[1];
	obj->edge[1][1] = &obj->node[2];
	obj->edge[2][0] = &obj->node[2];
	obj->edge[2][1] = &obj->node[3];
	obj->edge[3][0] = &obj->node[3];
	obj->edge[3][1] = &obj->node[0];
	obj->edge[4][0] = &obj->node[4];
	obj->edge[4][1] = &obj->node[5];
	obj->edge[5][0] = &obj->node[5];
	obj->edge[5][1] = &obj->node[6];
	obj->edge[6][0] = &obj->node[6];
	obj->edge[6][1] = &obj->node[7];
	obj->edge[7][0] = &obj->node[7];
	obj->edge[7][1] = &obj->node[4];
	obj->edge[8][0] = &obj->node[0];
	obj->edge[8][1] = &obj->node[4];
	obj->edge[9][0] = &obj->node[1];
	obj->edge[9][1] = &obj->node[5];
	obj->edge[10][0] = &obj->node[2];
	obj->edge[10][1] = &obj->node[6];
	obj->edge[11][0] = &obj->node[3];
	obj->edge[11][1] = &obj->node[7];
	return (obj);
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
	int		y;

	if (ft_strchr(str, ',') != NULL)
	{
		words = ft_split(str, ',');
		if (words == NULL)
			return (1);
		if (words[0] == NULL || words[1] == NULL || words[2] != NULL
			|| (ft_parse_int(words[0], &y)
				|| mlx_parse_hex_rgba(words[1], &point->color)))
		{
			ft_free_split(words, words);
			return (1);
		}
		ft_free_split(words, words);
		point->point.y = y;
	}
	else
	{
		if (ft_parse_int(str, &y))
			return (1);
		point->point.y = y;
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

int	parse_line(char *line, t_map_data *map)
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
			|| parse_node(splitted[count], (t_color_point *)map->nodes->next))
		{
			ft_free_split(splitted, splitted + count);
			return (1);
		}
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
	t_map_data	map;

	map.nodes = smart_new_d_list(ptr_manager(), NULL, NULL);
	map.x = -1;
	map.y = 0;
	line = get_next_line(fd);
	remove_endl(line);
	while (line != NULL)
	{
		if (parse_line(line, &map))
			ft_error();
		line = get_next_line(fd);
		++map.y;
	}
	map.nodes = map.nodes->next;
	smart_free(ptr_manager(), map.nodes->prev);
	return (map);
}

t_fdf_obj	*map_data_to_obj(t_map_data map)
{
	t_fdf_obj*const	obj = new_obj(map.x * map.y,
			2 * map.x * map.y - map.y - map.x);
	t_d_list		*del_node;
	size_t			idx;

	if (obj == NULL)
		ft_error();
	idx = 0;
	while (map.nodes != NULL)
	{
		obj->node[idx] = *(t_color_point *)map.nodes->value;
		++idx;
		del_node = map.nodes;
		map.nodes = map.nodes->next;
		smart_free(ptr_manager(), del_node);
	}
	return (obj);
}

int	validate_filename(const char *filename)
{
	if (ft_strlen(filename) < 4 || ft_ends_with(filename, ".fdf"))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int fd;
	t_fdf*const	fdf = new_fdf(1920, 1080, "fdf", true);

	fdf->obj = cube();
	vector3(&fdf->position, 100.0, 100.0, 100.0);
	if (argc != 2 || validate_filename(argv[1]))
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	fdf->obj = map_data_to_obj(parse_map(fd));
	mlx_key_hook(fdf->mlx, key_hook, fdf);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
