/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:04:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/25 19:07:01 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "../fdf_obj/fdf_obj.h"
#include <stdio.h>

void	draw_axis(t_fdf *fdf, t_matrix3 *trans)
{
	size_t	idx;

	copy_fdf_obj(fdf->tmp_axis, fdf->axis);
	idx = 0;
	while (idx < fdf->tmp_axis->cnt_node)
	{
		v3_transform(&fdf->tmp_axis->node[idx].point,
			&fdf->tmp_axis->node[idx].point, trans);
		++idx;
	}
	fdf_draw(fdf->img, fdf_translate(fdf->tmp_axis, fdf->position));
}

void	fdf_proj(t_fdf	*fdf)
{
	t_matrix3		trans;
	t_matrix3		tmp;
	size_t			idx;

	copy_fdf_obj(fdf->tmp_obj, fdf->obj);
	v3_add(&fdf->scale, &fdf->scale, &fdf->d_scale);
	v3_add(&fdf->rad, &fdf->rad, &fdf->d_rad);
	v3_add(&fdf->position, &fdf->position, &fdf->d_pos);
	m3_multiply(&trans,
		m3_multiply(&trans,
			m3_multiply(&trans,
				m3_scaling(&trans, fdf->scale.x, fdf->scale.y, fdf->scale.z),
				m3_rotate_z(&tmp, fdf->rad.z)),
			m3_rotate_x(&tmp, fdf->rad.x)),
		m3_rotate_y(&tmp, fdf->rad.y));
	idx = 0;
	while (idx < fdf->tmp_obj->cnt_node)
	{
		v3_transform(&fdf->tmp_obj->node[idx].point,
			&fdf->tmp_obj->node[idx].point, &trans);
		++idx;
	}
	fdf_draw(fdf->img, fdf_translate(fdf->tmp_obj, fdf->position));
	if (fdf->with_axis == 1)
		draw_axis(fdf, &trans);
}
