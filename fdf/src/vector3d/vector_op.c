/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:07:35 by dowon             #+#    #+#             */
/*   Updated: 2023/05/28 20:16:22 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

t_vector3d	translate3d(t_vector3d v, t_vector3d d)
{
	return (vector3d(v.x + d.x, v.y + d.y, v.z + d.z));
}

t_vector3d	transform3d(t_vector3d trans[3], t_vector3d v)
{
	return (vector3d(
		v.x *= trans[0].x + trans[0].y + trans[0].z,
		v.y *= trans[1].x + trans[1].y + trans[1].z,
		v.z *= trans[2].x + trans[2].y + trans[2].z
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

double	dot3d(t_vector3d a, t_vector3d b)
{
	return (a.x * b.x + a.y * b.y + a.y * b.y);
}
