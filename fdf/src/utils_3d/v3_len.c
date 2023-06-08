/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:06:37 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:09:18 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"
#include <math.h>

float	v3_lensq(const t_vector3 *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

float	v3_len(const t_vector3 *v)
{
	return (sqrtf(v3_lensq(v)));
}
