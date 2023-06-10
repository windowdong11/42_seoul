/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:10:46 by dowon             #+#    #+#             */
/*   Updated: 2023/06/09 15:55:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_3d.h"

t_vector3	*vector3(t_vector3 *out, float x, float y, float z)
{
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vector3	*v3_unit(t_vector3 *out, const t_vector3 *v)
{
	return (v3_div(out, v, v3_len(v)));
}

t_vector3	*v3_zero(t_vector3 *out)
{
	return (vector3(out, 0, 0, 0));
}
