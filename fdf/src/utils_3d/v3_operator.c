/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:26:11 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 21:34:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

t_vector3	*v3_cross(t_vector3 *out, const t_vector3 *p1, const t_vector3 *p2)
{
	t_vector3	result;

	result.x = p1->y * p2->z - p1->z * p2->y;
	result.y = p1->z * p2->x - p1->x * p2->z;
	result.z = p1->x * p2->y - p1->y * p2->x;
	out->x = result.x;
	out->y = result.y;
	out->z = result.z;
	return (out);
}

float	v3_dot(const t_vector3 *v1, const t_vector3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
