/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:42:25 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 22:00:41 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"
#include <math.h>

/* 
@return x-axis rotation matrix
*/
t_matrix3	*m3_rotate_x(t_matrix3 *out, float rad)
{
	m3_zero(out);
	out->v[0].x = 1;
	out->v[0].y = 0;
	out->v[0].z = 0;
	out->v[1].x = 0;
	out->v[1].y = cosf(rad);
	out->v[1].z = sinf(rad);
	out->v[2].x = 0;
	out->v[2].y = -sinf(rad);
	out->v[2].z = cosf(rad);
	return (out);
}

/* 
@return y-axis rotation matrix
*/
t_matrix3	*m3_rotate_y(t_matrix3 *out, float rad)
{
	m3_zero(out);
	out->v[0].x = cosf(rad);
	out->v[0].y = 0;
	out->v[0].z = -sinf(rad);
	out->v[1].x = 0;
	out->v[1].y = 1;
	out->v[1].z = 0;
	out->v[2].x = sinf(rad);
	out->v[2].y = 0;
	out->v[2].z = cosf(rad);
	return (out);
}

/* 
@return z-axis rotation matrix
*/
t_matrix3	*m3_rotate_z(t_matrix3 *out, float rad)
{
	m3_zero(out);
	out->v[0].x = cosf(rad);
	out->v[0].y = sinf(rad);
	out->v[0].z = 0;
	out->v[1].x = -sinf(rad);
	out->v[1].y = cosf(rad);
	out->v[1].z = 0;
	out->v[2].x = 0;
	out->v[2].y = 0;
	out->v[2].z = 1;
	return (out);
}
