/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_archimethic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:42 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:06:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

t_vector3	*v3_pow(t_vector3 *out, const t_vector3 *v, float n)
{
	return (vector3(out, v->x * n, v->y * n, v->z * n));
}

t_vector3	*v3_div(t_vector3 *out, const t_vector3 *v, float n)
{
	return (vector3(out, v->x / n, v->y / n, v->z / n));
}
