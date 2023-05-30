/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/05/30 20:47:40 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./utils/colors.h"
#include "./mlx_utils/mlx_utils.h"
#include "./vector3d/vector3d.h"
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

typedef struct s_point2d {
	int	x;
	int	y;
}	t_point2d;

void	draw_line(mlx_image_t *img, t_point2d p1, t_point2d p2)
{
	t_point2d	delta;
	t_point2d	point;

	delta.x = (p2.x - p1.x);
	delta.y = (p2.y - p1.y);
	point = p1;
	if (abs(delta.x) >= abs(delta.y))
	{
		if (p1.x > p2.x) {
			t_point2d p = p1;
			p1 = p2;
			p2 = p;
		}
		delta.x = (p2.x - p1.x);
		delta.y = (p2.y - p1.y);
		point = p1;
		while (point.x <= p2.x)
		{
			if (abs(2 * (delta.y * (point.x - p1.x) + delta.x * (p1.y - point.y))) > delta.x)
			{
				if (p1.y < p2.y)
					point.y++;
				else
					point.y--;
			}
			mlx_put_pixel(img, point.x, point.y, my_mlx_rgba(255, 0, 0, 100));
			point.x++;
		}
	}
	else
	{
		if (p1.y > p2.y) {
			t_point2d p = p1;
			p1 = p2;
			p2 = p;
		}
		delta.x = (p2.x - p1.x);
		delta.y = (p2.y - p1.y);
		point = p1;
		while (point.y <= p2.y)
		{
			if (abs(2 * (delta.x * (point.y - p1.y) + delta.y * (p1.x - point.x))) > delta.y)
			{
				if (p1.x < p2.x)
					point.x++;
				else
					point.x--;
			}
			mlx_put_pixel(img, point.x, point.y, my_mlx_rgba(0, 255, 0, 100));
			point.y++;
		}
	}
}

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
    ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
