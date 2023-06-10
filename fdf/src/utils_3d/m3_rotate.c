/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:42:25 by dowon             #+#    #+#             */
/*   Updated: 2023/06/09 15:41:37 by dowon            ###   ########.fr       */
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
	out->_11 = 1;
	out->_12 = 0;
	out->_13 = 0;
	out->_21 = 0;
	out->_22 = cosf(rad);
	out->_23 = sinf(rad);
	out->_31 = 0;
	out->_32 = -sinf(rad);
	out->_33 = cosf(rad);
	return (out);
}

/* 
@return y-axis rotation matrix
*/
t_matrix3	*m3_rotate_y(t_matrix3 *out, float rad)
{
	m3_zero(out);
	out->_11 = cosf(rad);
	out->_12 = 0;
	out->_13 = -sinf(rad);
	out->_21 = 0;
	out->_22 = 1;
	out->_23 = 0;
	out->_31 = sinf(rad);
	out->_32 = 0;
	out->_33 = cosf(rad);
	return (out);
}

/* 
@return z-axis rotation matrix
*/
t_matrix3	*m3_rotate_z(t_matrix3 *out, float rad)
{
	m3_zero(out);
	out->_11 = cosf(rad);
	out->_12 = sinf(rad);
	out->_13 = 0;
	out->_21 = -sinf(rad);
	out->_22 = cosf(rad);
	out->_23 = 0;
	out->_31 = 0;
	out->_32 = 0;
	out->_33 = 1;
	return (out);
}
