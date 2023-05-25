/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 20:20:02 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./utils/colors.h"
#include "./mlx_utils/mlx_utils.h"
#include "MLX42/MLX42.h"
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


void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = (char *)img->pixels;
	dst += x + y;
	*((unsigned int*)dst) = color;
}

// Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

typedef struct s_vector3d
{
	int x;
	int y;
	int z;
}	t_vector3d;

t_vector3d	transform3d(t_vector3d trans[3], t_vector3d v)
{
	t_vector3d	result;

	result.x = trans[0].x * v.x + trans[0].y * v.x + trans[0].z * v.x;
	result.y = trans[1].x * v.y + trans[1].y * v.y + trans[1].z * v.y;
	result.z = trans[2].x * v.z + trans[2].y * v.z + trans[2].z * v.z;
	return (result);
}

int	main(void)
{
	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	/* mlx_t* mlx = mlx_init(1920, 1080, "fdf", true);
	if (!mlx)
		ft_error();

	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
    ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	mlx_put_pixel(img, 100, 100, my_mlx_rgba(0, 0, 0, 100));
	mlx_put_pixel(img, 200, 200, my_mlx_rgba(0, 0, 0, 100));
	mlx_put_pixel(img, 100, 200, my_mlx_rgba(0, 0, 0, 100));
	mlx_put_pixel(img, 200, 100, my_mlx_rgba(0, 0, 0, 100));

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx); */
	t_vector3d tr[3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	};
	t_vector3d v = {19, 7, 32};
	t_vector3d tf = transform3d(tr, v);
	printf("x: %d, y: %d, z:%d\n", tf.x, tf.y, tf.z);
	return (EXIT_SUCCESS);
}
