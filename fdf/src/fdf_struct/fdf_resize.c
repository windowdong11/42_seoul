/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:19:55 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 22:40:21 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_struct.h"

void	move_coord_to_center(t_fdf_obj *obj)
{
	size_t		idx;
	const float	mid_x = obj->width_x / 2;
	const float	mid_y = obj->length_y / 2;
	const float	mid_z = (obj->max_depth_z + obj->min_depth_z) / 2;

	idx = 0;
	while (idx < obj->cnt_node)
	{
		obj->node[idx].point.x -= mid_x;
		obj->node[idx].point.y -= mid_y;
		obj->node[idx].point.z -= mid_z;
		++idx;
	}
}
