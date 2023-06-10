/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:17:14 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 17:59:02 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "../utils/swap.h"
#include <stdlib.h>

void	draw_line(mlx_image_t *img, int p1[2], int p2[2], t_rgba color)
{
	const int	axis = abs(p2[0] - p1[0]) < abs(p2[1] - p1[1]);
	int			delta[2];
	int			unit[2];
	int			point[2];

	delta[0] = p2[0] - p1[0];
	delta[1] = p2[1] - p1[1];
	if (p1[axis] > p2[axis])
	{
		swap_int(p1 + 0, p2 + 0);
		swap_int(p1 + 1, p2 + 1);
		delta[axis] = -delta[axis];
		delta[!axis] = -delta[!axis];
	}
	point[0] = p1[0];
	point[1] = p1[1];
	unit[axis] = 1;
	unit[!axis] = 1 - 2 * (delta[!axis] < 0);
	while (point[axis] <= p2[axis])
	{
		if ((axis == 0 && (point[axis] < 0 || point[axis] > (int)img->width || point[!axis] < 0 || point[!axis] > (int)img->height))
			|| (point[axis] < 0 || point[axis] > (int)img->height || point[!axis] < 0 || point[!axis] > (int)img->width))
		{
			point[axis] += unit[axis];
			continue ;
		}
		mlx_put_pixel(img, point[0], point[1], color);
		if (2 * abs(delta[!axis] * (point[axis] - p1[axis]) + delta[axis] * (p1[!axis] - point[!axis])) > delta[axis])
			point[!axis] += unit[!axis];
		point[axis] += unit[axis];
	}
}
