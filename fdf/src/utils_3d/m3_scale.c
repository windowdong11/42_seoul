/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:05:20 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:03:04 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

/*
@return (sx sy sz) scale matrix
*/
t_matrix3	*m3_scaling(t_matrix3 *out, float sx, float sy, float sz)
{
	m3_identity(out);
	out->_11 = sx;
	out->_22 = sy;
	out->_33 = sz;
	return (out);
}
