/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:04:55 by dowon             #+#    #+#             */
/*   Updated: 2023/05/28 20:07:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

t_vector3d	pow3d(t_vector3d v, double n)
{
	return (vector3d(v.x * n, v.y * n, v.z * n));
}

t_vector3d	div3d(t_vector3d v, double n)
{
	return (vector3d(v.x / n, v.y / n, v.z / n));
}
