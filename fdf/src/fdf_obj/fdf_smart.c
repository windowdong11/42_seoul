/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_smart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:07:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/19 18:03:21 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

void	delete_obj(void *ptr)
{
	t_fdf_obj*const	obj = ptr;

	if (obj == NULL)
		return ;
	smart_free(ptr_manager(), obj->edge);
	smart_free(ptr_manager(), obj->node);
	free(obj);
}

static t_fdf_obj	*fdf_obj_init(t_fdf_obj *obj)
{
	size_t	idx;

	obj->node = smart_malloc(ptr_manager(),
			sizeof(t_color_point) * obj->cnt_node, free);
	obj->edge = smart_malloc(ptr_manager(),
			sizeof(t_color_point **) * obj->cnt_edge, free);
	if (obj->node == NULL || obj->edge == NULL)
		smart_exit(ptr_manager(), EXIT_FAILURE);
	idx = 0;
	while (idx < obj->cnt_edge)
	{
		obj->edge[idx]
			= smart_malloc(ptr_manager(), sizeof(t_point3d *) * 2, free);
		if (obj->edge[idx] == NULL)
			smart_exit(ptr_manager(), EXIT_FAILURE);
		obj->edge[idx][0] = NULL;
		obj->edge[idx][1] = NULL;
		++idx;
	}
	return (obj);
}

t_fdf_obj	*new_obj(size_t points, size_t edges)
{
	t_fdf_obj*const	obj
		= smart_malloc(ptr_manager(), sizeof(t_fdf_obj), delete_obj);

	if (obj == NULL)
		smart_exit(ptr_manager(), EXIT_FAILURE);
	obj->cnt_node = points;
	obj->cnt_edge = edges;
	fdf_obj_init(obj);
	return (obj);
}
