/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:17:14 by dowon             #+#    #+#             */
/*   Updated: 2023/06/24 18:27:16 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "../utils/swap.h"
#include <stdlib.h>
#include <libft.h>

static void	copy_point(int dest[2], const int src[2])
{
	dest[0] = src[0];
	dest[1] = src[1];
}

static void	draw_line_low(mlx_image_t *img, int p1[2], int p2[2], t_rgba color)
{
	const int	delta[2] = {p2[0] - p1[0], p2[1] - p1[1]};
	const int	dy = 1 + -2 * (delta[1] < 0);
	const int	opt[3] = {2 * delta[1] * dy - delta[0],
		2 * (delta[1] * dy - delta[0]), 2 * delta[1] * dy};
	int			stack;
	int			point[2];

	copy_point(point, p1);
	stack = opt[0];
	while (point[0] <= p2[0])
	{
		if (!(point[0] < 0 || point[0] >= (int)img->width
				|| point[1] < 0 || point[1] >= (int)img->height))
			mlx_put_pixel(img, point[0], point[1], color);
		point[0] += 1;
		if (stack > 0)
		{
			stack += opt[1];
			point[1] += dy;
		}
		else
			stack += opt[2];
	}
}

static void	draw_line_high(mlx_image_t *img, int p1[2], int p2[2], t_rgba color)
{
	const int	delta[2] = {p2[0] - p1[0], p2[1] - p1[1]};
	const int	dx = 1 + -2 * (delta[0] < 0);
	const int	opt[3] = {2 * delta[0] * dx - delta[1],
		2 * (delta[0] * dx - delta[1]), 2 * delta[0] * dx};
	int			stack;
	int			point[2];

	copy_point(point, p1);
	stack = opt[0];
	while (point[1] <= p2[1])
	{
		if (!(point[0] < 0 || point[0] >= (int)img->width
				|| point[1] < 0 || point[1] >= (int)img->height))
			mlx_put_pixel(img, point[0], point[1], color);
		point[1] += 1;
		if (stack > 0)
		{
			stack += opt[1];
			point[0] += dx;
		}
		else
			stack += opt[2];
	}
}

// static void	move_point_inbound(int point[2], int width, int height)
// {
// 	if (point[0] < 0)
// 		point[0] = 0;
// 	else if (point[0] >= width)
// 		point[0] = width - 1;
// 	if (point[1] < 0)
// 		point[1] = 0;
// 	else if (point[1] >= height)
// 		point[1] = height - 1;
// }

void	draw_line(mlx_image_t *img, int p1[2], int p2[2], t_rgba color)
{
	// if (p1[0] < 0 || p1[0] >= (int)img->width
	// 	|| p1[1] < 0 || p1[1] >= (int)img->height
	// 	|| p2[0] < 0 || p2[0] >= (int)img->width
	// 	|| p2[1] < 0 || p2[1] >= (int)img->height)
	// 	return ;
	// move_point_inbound(p1, img->width, img->height);
	// move_point_inbound(p2, img->width, img->height);
	(void)color;
	if (abs(p2[0] - p1[0]) < abs(p2[1] - p1[1]))
	{
		if (p1[1] > p2[1])
			draw_line_high(img, p2, p1, my_mlx_rgba(255, 255, 0, 255));
		else
			draw_line_high(img, p1, p2, my_mlx_rgba(255, 255, 0, 255));
	}
	else
	{
		if (p1[0] > p2[0])
			draw_line_low(img, p2, p1, my_mlx_rgba(0, 255, 255, 255));
		else
			draw_line_low(img, p1, p2, my_mlx_rgba(0, 255, 255, 255));
	}
}
