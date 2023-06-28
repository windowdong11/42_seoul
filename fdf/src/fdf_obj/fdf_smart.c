/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_smart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:07:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 18:45:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"
#include "../ptr_manager/ptr_manager.h"
#include <smart_ptr.h>

void	delete_obj(void *ptr)
{
	t_fdf_obj*const	obj = ptr;
	size_t			idx;

	if (obj == NULL)
		return ;
	free(obj->node);
	obj->node = NULL;
	if (obj->edge != NULL)
	{
		idx = 0;
		while (idx < obj->cnt_edge)
		{
			free(obj->edge[idx]);
			obj->edge[idx] = NULL;
			++idx;
		}
	}
	free(obj->edge);
	free(obj);
}

static t_fdf_obj	*fdf_obj_init(t_fdf_obj *obj)
{
	size_t	idx;

	obj->node = malloc(sizeof(t_color_point) * obj->cnt_node);
	obj->edge = malloc(sizeof(t_color_point **) * obj->cnt_edge);
	if (obj->node == NULL || obj->edge == NULL)
		smart_exit(ptr_manager(), EXIT_FAILURE);
	idx = 0;
	while (idx < obj->cnt_edge)
	{
		obj->edge[idx] = malloc(sizeof(t_point3d *) * 2);
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
