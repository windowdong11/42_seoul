/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:07:35 by dowon             #+#    #+#             */
/*   Updated: 2023/06/05 20:24:18 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

t_vector3d	translate3d(t_vector3d v, t_vector3d d)
{
	return (vector3d(v.x + d.x, v.y + d.y, v.z + d.z));
}

t_vector3d	transform3d(t_vector3d trans[3], t_vector3d v)
{
	return (vector3d(
		v.x = trans[0].x * v.x + trans[1].x * v.y + trans[2].x * v.z,
		v.y = trans[0].y * v.x + trans[1].y * v.y + trans[2].y * v.z,
		v.z = trans[0].z * v.x + trans[1].z * v.y + trans[2].z * v.z
	));
}

t_vector3d*	cross3d(t_vector3d *pOut, const t_vector3d *p1, const t_vector3d *p2)
{
	t_vector3d	result;

	result.x = p1->y * p2->z - p1->z * p2->y;
	result.y = p1->z * p2->x - p1->x * p2->z;
	result.z = p1->x * p2->y - p1->y * p2->x;
	pOut->x = result.x;
	pOut->y = result.y;
	pOut->z = result.z;
	return (pOut);
}

/* dot product (inner product) */
float	dot3d(const t_vector3d *p1, const t_vector3d *p2)
{
	return (p1->x * p2->x + p1->y * p2->y + p1->y * p2->y);
}
