/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:08:24 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 17:48:39 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	draw_point3d(mlx_image_t *img, t_point3d p, t_rgba color)
{
	mlx_put_pixel(img, (uint32_t)p.x, (uint32_t)p.y, color);
}

void	draw_line3d(mlx_image_t *img, t_point3d p1, t_point3d p2, t_rgba color)
{
	draw_line(img, (int [2]){p1.x, p1.y}, (int [2]){p2.x, p2.y}, color);
}
