/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_to_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:30:50 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 23:27:01 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "../exception/exception.h"
#include "../utils/float.h"

static void	connect_right(t_fdf_obj *obj, int idx, int x, int y)
{
	obj->edge[idx][0] = obj->node + obj->width_x * y + x;
	obj->edge[idx][1] = obj->node + obj->width_x * y + x + 1;
}

static void	connect_down(t_fdf_obj *obj, int idx, int x, int y)
{
	obj->edge[idx][0] = obj->node + obj->width_x * y + x;
	obj->edge[idx][1] = obj->node + obj->width_x * (y + 1) + x;
}

static void	connect_nodes(t_fdf_obj *obj)
{
	size_t	idx;
	size_t	y;
	size_t	x;

	idx = 0;
	y = 0;
	while (y < obj->length_y - 1)
	{
		x = 0;
		while (x < obj->width_x - 1)
		{
			connect_right(obj, idx++, x, y);
			connect_down(obj, idx++, x, y);
			++x;
		}
		connect_down(obj, idx++, obj->width_x - 1, y);
		++y;
	}
	x = 0;
	while (x < obj->width_x - 1)
	{
		connect_right(obj, idx++, x, obj->length_y - 1);
		++x;
	}
}

t_fdf_obj	*map_data_to_obj(t_map_data map)
{
	t_fdf_obj*const	obj = new_obj(map.x * map.y,
			((map.x - 1) * map.y) + ((map.y - 1) * map.x));
	t_d_list		*del_node;
	size_t			idx;

	if (obj == NULL)
		ft_error("malloc failed\n");
	idx = 0;
	obj->width_x = map.x;
	obj->length_y = map.y;
	while (map.nodes != NULL)
	{
		obj->node[idx].point = ((t_color_point *)map.nodes->value)->point;
		obj->max_depth_z = maxf(obj->max_depth_z, obj->node[idx].point.z);
		obj->min_depth_z = minf(obj->min_depth_z, obj->node[idx].point.z);
		obj->node[idx].color = ((t_color_point *)map.nodes->value)->color;
		++idx;
		del_node = map.nodes;
		map.nodes = map.nodes->next;
		del_node->destructor(del_node->value);
		free(del_node);
	}
	connect_nodes(obj);
	return (obj);
}
