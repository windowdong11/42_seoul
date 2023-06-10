/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_archimethic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:42 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 22:51:08 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

t_vector3	*v3_add(t_vector3 *out, const t_vector3 *v1, const t_vector3 *v2)
{
	out->x = v1->x + v2->x;
	out->y = v1->y + v2->y;
	out->z = v1->z + v2->z;
	return (out);
}

t_vector3	*v3_pow(t_vector3 *out, const t_vector3 *v, float n)
{
	return (vector3(out, v->x * n, v->y * n, v->z * n));
}

t_vector3	*v3_div(t_vector3 *out, const t_vector3 *v, float n)
{
	return (vector3(out, v->x / n, v->y / n, v->z / n));
}

t_vector3	*v3_negate(t_vector3 *out, const t_vector3 *v)
{
	return (vector3(out, -v->x, -v->y, -v->z));
}
