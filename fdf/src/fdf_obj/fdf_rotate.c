/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:17:39 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 17:27:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

t_fdf_obj	*fdf_rotate_x(t_fdf_obj	*obj, float rad)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_rotate_x(&transformer, rad);
	while (idx < obj->cnt_point)
	{
		v3_transform(&obj->node[idx].point, &obj->node[idx].point, &transformer);
		++idx;
	}
	return (obj);
}

t_fdf_obj	*fdf_rotate_y(t_fdf_obj	*obj, float rad)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_rotate_y(&transformer, rad);
	while (idx < obj->cnt_point)
	{
		v3_transform(&obj->node[idx].point, &obj->node[idx].point, &transformer);
		++idx;
	}
	return (obj);
}

t_fdf_obj	*fdf_rotate_z(t_fdf_obj	*obj, float rad)
{
	t_matrix3	transformer;
	size_t		idx;

	idx = 0;
	m3_rotate_z(&transformer, rad);
	while (idx < obj->cnt_point)
	{
		v3_transform(&obj->node[idx].point, &obj->node[idx].point, &transformer);
		++idx;
	}
	return (obj);
}
