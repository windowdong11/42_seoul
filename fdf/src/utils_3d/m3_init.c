/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:41:53 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:20:48 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

t_matrix3	*m3_zero(t_matrix3 *out)
{
	int	idx;

	idx = 0;
	while (idx < 3)
	{
		out->m[idx][0] = 0;
		out->m[idx][1] = 0;
		out->m[idx][2] = 0;
		idx++;
	}
	return (out);
}

t_matrix3	*m3_identity(t_matrix3 *out)
{
	out->_12 = 0;
	out->_13 = 0;
	out->_21 = 0;
	out->_23 = 0;
	out->_31 = 0;
	out->_32 = 0;
	return (out);
}
