/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:04:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/19 16:47:21 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "../fdf_obj/fdf_obj.h"

void	fdf_proj(t_fdf	*fdf)
{
	t_fdf_obj*const	obj = copy_fdf_obj(fdf->obj);
	t_matrix3		trans;
	t_matrix3		tmp;
	size_t			idx;

	v3_add(&fdf->scale, &fdf->scale, &fdf->d_scale);
	v3_add(&fdf->rad, &fdf->rad, &fdf->d_rad);
	v3_add(&fdf->position, &fdf->position, &fdf->d_pos);
	m3_multiply(&trans, 
		m3_multiply(&trans,
			m3_multiply(&trans,
				m3_scaling(&trans, fdf->scale.x, fdf->scale.y, fdf->scale.z),
				m3_rotate_z(&tmp, fdf->rad.z)
			),
			m3_rotate_x(&tmp, fdf->rad.x)
		),
		m3_rotate_y(&tmp, fdf->rad.y)
	);
	idx = 0;
	while (idx < obj->cnt_node)
	{
		v3_transform(&obj->node[idx].point,
			&obj->node[idx].point, &trans);
		++idx;
	}
	if (fdf->with_axis == 1)
		draw_axis(fdf, &(t_vector3){100.0, 100.0, 100.0}, trans);
	fdf_draw_at(fdf->img, obj, fdf->position);
	smart_free(ptr_manager(), obj);
}
