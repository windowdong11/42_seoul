/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:46:29 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 22:28:47 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../utils_3d/utils_3d.h"
# include "../utils/colors.h"
# include <MLX42/MLX42.h>

typedef union u_color_point
{
	struct {
		t_point3d	point;
		t_rgba		color;
	};
	float	p[3];
}	t_color_point;

void	draw_line(mlx_image_t *img, int p1[2], int p2[2], t_rgba color);
void	draw_point3d(mlx_image_t *img, t_point3d p, t_rgba color);
void	draw_line3d(mlx_image_t *img, t_point3d p1, t_point3d p2, t_rgba color);

#endif
