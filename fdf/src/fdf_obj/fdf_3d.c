/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:17:39 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:31:00 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

t_fdf_obj	*fdf_rotate_x(t_fdf_obj	*obj, float angle)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_rotate_x(&transformer, angle);
	while (idx < obj->cnt_point)
	{
		v3_transform(obj->point + idx, obj->point + idx, &transformer);
		++idx;
	}
	return (obj);
}

t_fdf_obj	*fdf_rotate_y(t_fdf_obj	*obj, float angle)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_rotate_y(&transformer, angle);
	while (idx < obj->cnt_point)
	{
		v3_transform(obj->point + idx, obj->point + idx, &transformer);
		++idx;
	}
	return (obj);
}

t_fdf_obj	*fdf_rotate_z(t_fdf_obj	*obj, float angle)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_rotate_z(&transformer, angle);
	while (idx < obj->cnt_point)
	{
		v3_transform(obj->point + idx, obj->point + idx, &transformer);
		++idx;
	}
	return (obj);
}
