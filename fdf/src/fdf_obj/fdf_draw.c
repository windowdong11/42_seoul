/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:15 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 19:00:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"
#include "../mlx_utils/mlx_utils.h"

// void	draw_colored(mlx_image_t *img, t_color_point *p1, t_color_point *p2)
// {
// 	(p1->p[0] - p2->p[0]) * (p1->p[1] - p2.p[1]) < 0.0
// }

void	fdf_draw(mlx_image_t *img, t_fdf_obj *obj)
{
	size_t	i;

	i = 0;
	while (i < obj->cnt_edge)
	{
		draw_line3d(img,
			obj->edge[i][0]->point, obj->edge[i][1]->point,
			obj->edge[i][1]->color);
		++i;
	}
}

void	fdf_draw_at(mlx_image_t *img, t_fdf_obj *obj, t_vector3 at)
{
	fdf_translate(obj, at);
	fdf_draw(img, obj);
	fdf_translate(obj, *v3_negate(&at, &at));
}
