/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/06/12 20:47:37 by dowon            ###   ########.fr       */
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
int	ends_with(const char *str, const char *end)
{
	const char*const	str_start = str;
	const char*const	end_start = str;

	while (*str != '\0')
		str++;
	while (*end != '\0')
		end++;
	if (str - str_start < end - end_start)
		return (0);
	while (str >= str_start && end >= end_start)
	{
		if (*str != *end)
			return (0);
		--str;
		--end;
	}
	return (1);
}

#include <fcntl.h>
#include <get_next_line.h>

t_fdf_obj	*parse_node(char *splitted)
{

}

t_fdf_obj	*parse_map(int fd)
{
	char		*line;
	char		**splitted;
	t_fdf_obj	*obj;

	line = get_next_line(fd);
	while (line != NULL)
	{
		splitted = ft_split(line, ' ');
		if (splitted == NULL)
			ft_error();
		parse_each_node(splitted);
		while (*splitted != NULL)
		{
			parse_node(*splitted);
			free(*splitted);
			(*splitted)++;
		}
		free(splitted);
	}
	return (NULL);
}

int	validate_filename(const char *filename)
{
	if (ft_strlen(filename) < 4 || ends_with(filename, ".fdf"))
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
	fdf->obj = parse_map(fd);
	mlx_key_hook(fdf->mlx, key_hook, fdf);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
