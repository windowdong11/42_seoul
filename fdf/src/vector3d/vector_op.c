/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:07:35 by dowon             #+#    #+#             */
/*   Updated: 2023/06/02 19:29:50 by dowon            ###   ########.fr       */
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

t_vector3d	cross3d(t_vector3d a, t_vector3d b)
{
	return (vector3d(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	));
}

/* dot product (inner product) */
double	dot3d(t_vector3d a, t_vector3d b)
{
	return (a.x * b.x + a.y * b.y + a.y * b.y);
}
