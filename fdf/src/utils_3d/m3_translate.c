/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:43:01 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 20:43:42 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

t_matrix3	*m3_translation(t_matrix3 *out, float x, float y, float z)
{
	m3_identity(out);
	out->_11 = x;
	out->_21 = y;
	out->_31 = z;
	return (out);
}
