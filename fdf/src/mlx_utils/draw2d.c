/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:17:14 by dowon             #+#    #+#             */
/*   Updated: 2023/06/25 20:02:43 by dowon            ###   ########.fr       */
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

void	draw_line(mlx_image_t *img, int p1[2], int p2[2], t_rgba color)
{
	if (abs(p2[0] - p1[0]) < abs(p2[1] - p1[1]))
	{
		if (p1[1] > p2[1])
			draw_line_high(img, p2, p1, color);
		else
			draw_line_high(img, p1, p2, color);
	}
	else
	{
		if (p1[0] > p2[0])
			draw_line_low(img, p2, p1, color);
		else
			draw_line_low(img, p1, p2, color);
	}
}
