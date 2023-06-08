/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:35:18 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./utils/colors.h"
#include "./mlx_utils/mlx_utils.h"
#include "utils/angle.h"
#include "utils_3d/utils_3d.h"
#include "fdf_obj/fdf_obj.h"
#include <smart_ptr.h>
#include "MLX42/MLX42.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



/*
mlx_pixel_put
mlx_new_image
mlx_key_hook
mlx_mouse_hook
mlx_expose_hook // window should be re-drawn (this is called an "expose" event
mlx_loop_hook
mlx_new_image
mlx_get_data_addr
mlx_put_image_to_window
mlx_get_color_value
mlx_xpm_to_image
 */

t_smart_manager	*obj_manager(void)
{
	static t_smart_manager	manager;

	return (&manager);
}

void	delete_obj(void *ptr)
{
	t_fdf_obj*const	obj = ptr;

	if (obj == NULL)
		return ;
	smart_free(obj_manager(), obj->edge);
	smart_free(obj_manager(), obj->point);
	smart_free(obj_manager(), obj);
}

t_fdf_obj	*new_obj(size_t points, size_t edges)
{
	t_fdf_obj*const	obj
		= smart_malloc(obj_manager(), sizeof(t_fdf_obj), delete_obj);
	size_t			idx;

	if (obj == NULL)
		smart_exit(obj_manager(), EXIT_FAILURE);
	obj->point = smart_malloc(obj_manager(), sizeof(t_point3d) * points, free);
	obj->edge = smart_malloc(obj_manager(), sizeof(t_point3d **) * edges, free);
	if (obj->point == NULL || obj->edge == NULL)
		smart_exit(obj_manager(), EXIT_FAILURE);
	obj->cnt_point = points;
	obj->cnt_edge = edges;
	idx = 0;
	while (idx < edges)
	{
		obj->edge[idx]
			= smart_malloc(obj_manager(), sizeof(t_point3d *) * 2, free);
		if (obj->edge[idx] == NULL)
			smart_exit(obj_manager(), EXIT_FAILURE);
		obj->edge[idx][0] = NULL;
		obj->edge[idx][1] = NULL;
		++idx;
	}
	return (obj);
}

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = (char *)img->pixels;
	dst += x + y;
	*((unsigned int *)dst) = color;
}

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

typedef struct s_point2d_ptr
{
	int	*axis;
	int	*v_axis;
}	t_point2d_ptr;

void	swap_ptr(void **p1, void **p2)
{
	void	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	draw_line(mlx_image_t *img, int p1[2], int p2[2], t_rgba color)
{
	const int	axis = abs(p2[0] - p1[0]) < abs(p2[1] - p1[1]);
	int			delta[2];
	int			unit[2];
	int			point[2];
	int			tmp;

	delta[0] = p2[0] - p1[0];
	delta[1] = p2[1] - p1[1];
	if (p1[axis] > p2[axis])
	{
		tmp = p1[0];
		p1[0] = p2[0];
		p2[0] = tmp;
		tmp = p1[1];
		p1[1] = p2[1];
		p2[1] = tmp;
		delta[axis] = -delta[axis];
		delta[!axis] = -delta[!axis];
	}
	point[0] = p1[0];
	point[1] = p1[1];
	unit[axis] = 1;
	unit[!axis] = 1 - 2 * (delta[!axis] < 0);
	while (point[axis] <= p2[axis])
	{
		if (point[axis] < 0 || point[axis] > 500 || point[!axis] < 0 || point[!axis] > 500)
			return ;
		mlx_put_pixel(img, point[0], point[1], color);
		if (2 * abs(delta[!axis] * (point[axis] - p1[axis]) + delta[axis] * (p1[!axis] - point[!axis])) > delta[axis])
			point[!axis] += unit[!axis];
		point[axis] += unit[axis];
	}
}

void draw_point3d(mlx_image_t *img, t_point3d p, t_rgba color)
{
	mlx_put_pixel(img, (uint32_t)p.x, (uint32_t)p.y, color);
}

void draw_line3d(mlx_image_t *img, t_point3d p1, t_point3d p2, t_rgba color)
{
	draw_line(img, (int [2]){p1.x, p1.y}, (int [2]){p2.x, p2.y}, color);
}

/* void rotateX(t_fdf_obj *obj, double rad)
{
	t_matrix3 transformer[3] = {
		{1, 0, 0},
		{0, cos(rad), sin(rad)},
		{0, -sin(rad), cos(rad)},
	};

	for (size_t i = 0; i < obj->cnt_point; i++)
		obj->point[i] = transform3d(transformer, obj->point[i]);
}

void rotateY(t_fdf_obj *obj, double rad)
{
	t_vector3d transformer[3] = {
		{cos(rad), 0, sin(rad)},
		{0, 1, 0},
		{-sin(rad), 0, cos(rad)},
	};

	for (size_t i = 0; i < obj->cnt_point; i++)
		obj->point[i] = transform3d(transformer, obj->point[i]);
}

void rotateZ(t_fdf_obj *obj, double rad)
{
	t_vector3d transformer[3] = {
		{cos(rad), sin(rad), 0},
		{-sin(rad), cos(rad), 0},
		{0, 0, 1},
	};

	for (size_t i = 0; i < obj->cnt_point; i++)
		obj->point[i] = transform3d(transformer, obj->point[i]);
} */

void draw_obj(mlx_image_t *img, t_fdf_obj *obj)
{
	for(size_t i = 0; i < obj->cnt_edge; i++)
		draw_line3d(img, *obj->edge[i][0], *obj->edge[i][1], my_mlx_rgba(0, 0, 255, 255));
}

// Print the window width and height.
t_fdf_obj	*obj;
static void	ft_hook(void *param)
{
	// const mlx_image_t	*img = param;
	(void)param;
	// for (size_t i = 0; i < obj->cnt_point; i++)
	// 	obj->point[i] = v3_translate((t_vector3){400, 400, 0}, obj->point[i]);
	// draw_obj(img, obj);
	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

// t_fdf_obj	cube()
// {
// 	obj->point[0] = (t_point3d){-25, -25, -25};
// 	obj->point[1] = (t_point3d){25, -25, -25};
// 	obj->point[2] = (t_point3d){25, 25, -25};
// 	obj->point[3] = (t_point3d){-25, 25, -25};
// 	obj->point[4] = (t_point3d){-25, -25, 25};
// 	obj->point[5] = (t_point3d){25, -25, 25};
// 	obj->point[6] = (t_point3d){25, 25, 25};
// 	obj->point[7] = (t_point3d){-25, 25, 25};
// }

/* 
정점들 입력 &
간선들에 대한 정보
(0, 1)
(0, 2)
(0, 3)
*/
int	main(void)
{
	mlx_t	*mlx = mlx_init(1920, 1080, "fdf", true);
	if (!mlx)
		ft_error();

	mlx_image_t	*img = mlx_new_image(mlx, 1920, 1080);
    ft_memset(img->pixels, 0, img->width * img->height * sizeof(int));
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	t_fdf_obj	*axis = new_obj(4, 3);
	axis->point[0] = (t_point3d){0, 0, 0};
	axis->point[1] = (t_point3d){100, 0, 0};
	axis->point[2] = (t_point3d){0, 100, 0};
	axis->point[3] = (t_point3d){0, 0, 100};
	axis->edge[0][0] = &axis->point[0];
	axis->edge[0][1] = &axis->point[1];
	axis->edge[1][0] = &axis->point[0];
	axis->edge[1][1] = &axis->point[2];
	axis->edge[2][0] = &axis->point[0];
	axis->edge[2][1] = &axis->point[3];

	obj = new_obj(8, 12);
	obj->point[0] = (t_point3d){-25, -25, -25};
	obj->point[1] = (t_point3d){25, -25, -25};
	obj->point[2] = (t_point3d){25, 25, -25};
	obj->point[3] = (t_point3d){-25, 25, -25};
	obj->point[4] = (t_point3d){-25, -25, 25};
	obj->point[5] = (t_point3d){25, -25, 25};
	obj->point[6] = (t_point3d){25, 25, 25};
	obj->point[7] = (t_point3d){-25, 25, 25};
	obj->edge[0][0] = &obj->point[0];
	obj->edge[0][1] = &obj->point[1];
	obj->edge[1][0] = &obj->point[1];
	obj->edge[1][1] = &obj->point[2];
	obj->edge[2][0] = &obj->point[2];
	obj->edge[2][1] = &obj->point[3];
	obj->edge[3][0] = &obj->point[3];
	obj->edge[3][1] = &obj->point[0];
	obj->edge[4][0] = &obj->point[4];
	obj->edge[4][1] = &obj->point[5];
	obj->edge[5][0] = &obj->point[5];
	obj->edge[5][1] = &obj->point[6];
	obj->edge[6][0] = &obj->point[6];
	obj->edge[6][1] = &obj->point[7];
	obj->edge[7][0] = &obj->point[7];
	obj->edge[7][1] = &obj->point[4];
	obj->edge[8][0] = &obj->point[0];
	obj->edge[8][1] = &obj->point[4];
	obj->edge[9][0] = &obj->point[1];
	obj->edge[9][1] = &obj->point[5];
	obj->edge[10][0] = &obj->point[2];
	obj->edge[10][1] = &obj->point[6];
	obj->edge[11][0] = &obj->point[3];
	obj->edge[11][1] = &obj->point[7];
	draw8way(img);
	mlx_loop_hook(mlx, ft_hook, mlx);
	for (size_t i = 0; i < axis->cnt_point; i++)
		v3_translate(&axis->point[i], &axis->point[i], &(t_vector3){300, 300, 0});
	for (size_t i = 0; i < axis->cnt_point; i++)
		v3_translate(&axis->point[i], &axis->point[i], &(t_vector3){-300, -300, 0});
	fdf_rotate_y(axis, radf(30.0));
	for (size_t i = 0; i < axis->cnt_point; i++)
		v3_translate(&axis->point[i], &axis->point[i], &(t_vector3){300, 300, 0});
	for (size_t i = 0; i < axis->cnt_point; i++)
		v3_translate(&axis->point[i], &axis->point[i], &(t_vector3){-300, -300, 0});
	fdf_rotate_x(axis, radf(30.0));
	for (size_t i = 0; i < axis->cnt_point; i++)
		v3_translate(&axis->point[i], &axis->point[i], &(t_vector3){300, 300, 0});
	draw_line3d(img, *axis->edge[0][0], *axis->edge[0][1], my_mlx_rgba(255, 0, 0, 255));
	draw_line3d(img, *axis->edge[1][0], *axis->edge[1][1], my_mlx_rgba(0, 255, 0, 255));
	draw_line3d(img, *axis->edge[2][0], *axis->edge[2][1], my_mlx_rgba(0, 0, 255, 255));
	draw_obj(img, obj);
	// R: x-axis
	// G: y-axis
	// B: z-axis
	mlx_loop(mlx);
	mlx_loop_hook(mlx, ft_hook, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
