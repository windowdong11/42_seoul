/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:06:40 by dowon             #+#    #+#             */
/*   Updated: 2023/06/02 15:46:39 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

double	len3d_sq(t_vector3d v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	len3d(t_vector3d v)
{
	return (sqrt(len3d_sq(v)));
}
