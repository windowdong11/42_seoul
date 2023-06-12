/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:12:37 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 15:32:46 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

t_fdf_obj	*fdf_scale(t_fdf_obj *obj, const t_vector3 *scale)
{
	fdf_scale_x(obj, scale->x);
	fdf_scale_y(obj, scale->y);
	fdf_scale_z(obj, scale->z);
	return (obj);
}

t_fdf_obj	*fdf_scale_rev(t_fdf_obj *obj, const t_vector3 *scale)
{
	t_vector3	tmp;

	v3_negate(&tmp, scale);
	fdf_scale_z(obj, tmp.z);
	fdf_scale_y(obj, tmp.y);
	fdf_scale_x(obj, tmp.x);
	return (obj);
}

t_fdf_obj	*fdf_scale_x(t_fdf_obj *obj, float sx)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_scaling(&transformer, sx, 1.0, 1.0);
	while (idx < obj->cnt_node)
	{
		v3_transform(&obj->node[idx].point,
			&obj->node[idx].point, &transformer);
		++idx;
	}
	return (obj);
}

t_fdf_obj	*fdf_scale_y(t_fdf_obj *obj, float sy)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_scaling(&transformer, 1.0, sy, 1.0);
	while (idx < obj->cnt_node)
	{
		v3_transform(&obj->node[idx].point,
			&obj->node[idx].point, &transformer);
		++idx;
	}
	return (obj);
}

t_fdf_obj	*fdf_scale_z(t_fdf_obj *obj, float sz)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_scaling(&transformer, 1.0, 1.0, sz);
	while (idx < obj->cnt_node)
	{
		v3_transform(&obj->node[idx].point,
			&obj->node[idx].point, &transformer);
		++idx;
	}
	return (obj);
}
