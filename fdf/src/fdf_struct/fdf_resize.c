/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:19:55 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 18:32:08 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_struct.h"

void	move_coord_to_center(t_fdf_obj *obj)
{
	size_t	idx;

	idx = 0;
	while (idx < obj->cnt_node)
	{
		obj->node[idx].point.x -= obj->width_x / 2;
		obj->node[idx].point.y -= obj->length_y / 2;
		++idx;
	}
}
