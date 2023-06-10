/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:15 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 17:30:36 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"
#include "../mlx_utils/mlx_utils.h"

void		fdf_draw(mlx_image_t *img, t_fdf_obj *obj)
{
	for(size_t i = 0; i < obj->cnt_edge; i++)
		draw_line3d(img, obj->edge[i][0]->point, obj->edge[i][1]->point, my_mlx_rgba(0, 0, 255, 255));
}

void		fdf_draw_at(mlx_image_t *img, t_fdf_obj *obj, t_vector3 at)
{
	fdf_translate(obj, at);
	fdf_draw(img, obj);
	fdf_translate(obj, *v3_negate(&at, &at));
}
