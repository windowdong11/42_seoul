/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_to_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:30:50 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:19:52 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "../exception/exception.h"
#include "../utils/float.h"

void	connect(t_fdf_obj *obj, int idx, int x, int y, int nx, int ny)
{
	obj->edge[idx][0] = obj->node + obj->width_x * y + x;
	obj->edge[idx][1] = obj->node + obj->width_x * ny + nx;
}

t_fdf_obj	*map_data_to_obj(t_map_data map)
{
	t_fdf_obj*const	obj = new_obj(map.x * map.y,
			((map.x - 1) * map.y) + ((map.y - 1) * map.x));
	t_d_list		*del_node;
	size_t			idx;

	if (obj == NULL)
		ft_error();
	idx = 0;
	obj->width_x = map.x;
	obj->length_y = map.y;
	while (map.nodes != NULL)
	{
		obj->node[idx].point = ((t_color_point *)map.nodes->value)->point;
		obj->depth_z = maxf(obj->depth_z, obj->node[idx].point.z);
		obj->node[idx].color = ((t_color_point *)map.nodes->value)->color;
		++idx;
		del_node = map.nodes;
		map.nodes = map.nodes->next;
		del_node->destructor(del_node->value);
		free(del_node);
	}
	idx = 0;
	for (int y = 0; y < map.y; ++y) {
		for (int x = 0; x < map.x; ++x) {
			if (x + 1 != map.x)
			{
				connect(obj, idx, x, y, x + 1, y);
				++idx;
			}
			if (y + 1 != map.y)
			{
				connect(obj, idx, x, y, x, y + 1);
				++idx;
			}
		}
	}
	return (obj);
}
