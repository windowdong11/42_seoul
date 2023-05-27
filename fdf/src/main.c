/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/05/27 22:41:13 by dowon            ###   ########.fr       */
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
	*((unsigned int *)dst) = color;
}

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void	ft_hook(void *param)
{
	const mlx_t *mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

typedef struct s_vector3d
{
	int	x;
	int	y;
	int	z;
}	t_vector3d;

void	cross3d(t_vector3d *a, t_vector3d *b)
{
	a->x = a->y * b->z - a->z * b->y;
	a->y = a->z * b->x - a->x * b->z;
	a->z = a->x * b->y - a->y * b->x;
}

void	pow3d(t_vector3d *v, int n)
{
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

void	translate3d(t_vector3d *v, t_vector3d *d)
{
	v->x += d->x;
	v->y += d->y;
	v->z += d->z;
}

void	transform3d(t_vector3d trans[3], t_vector3d *v)
{
	v->x *= trans[0].x + trans[0].y + trans[0].z;
	v->y *= trans[1].x + trans[1].y + trans[1].z;
	v->z *= trans[2].x + trans[2].y + trans[2].z;
}

int	main(void)
{
	mlx_t* mlx = mlx_init(1920, 1080, "fdf", true);
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
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
