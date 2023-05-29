/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/05/29 20:45:24 by dowon            ###   ########.fr       */
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
/*
y = (y2 - y1)/(x2-x1) * (x - x1) + y1
1) (p1.x == p2.x) => (p1.y - p2.y)/(p1.x - p2.x) == INF (vertical)
2) (p1.y == p2.y) => (p1.y - p2.y)/(p1.x - p2.x) == 0 (horizontal)
3) 0 < (p1.y - p2.y)/(p1.x - p2.x) > 0
	3-1) (p1.y - p2.y)/(p1.x - p2.x) < 1
	3-2) 1 < (p1.y - p2.y)/(p1.x - p2.x)
4) (p1.y - p2.y)/(p1.x - p2.x) < 0
*/
void	draw_line(t_point2d p1, t_point2d p2)
{
	int			*start_point;
	int			*end_point;
	int			*vertical_point;
	const int	slope = (p1.y - p2.y)/(p1.x - p2.x)
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
	mlx_t* mlx = mlx_init(1920, 1080, "fdf", true);
	if (!mlx)
		ft_error();

	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
    ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	mlx_put_pixel(img, 150, 150, my_mlx_rgba(255, 0, 0, 100));
	mlx_put_pixel(img, 100, 100, my_mlx_rgba(0, 0, 0, 100));
	mlx_put_pixel(img, 200, 200, my_mlx_rgba(0, 0, 0, 100));
	mlx_put_pixel(img, 100, 200, my_mlx_rgba(0, 0, 0, 100));
	mlx_put_pixel(img, 200, 100, my_mlx_rgba(0, 0, 0, 100));

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
