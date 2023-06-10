/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_smart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:07:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 17:26:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

t_smart_manager	*fdf_obj_manager(void)
{
	static t_smart_manager	manager;

	return (&manager);
}

void	delete_obj(void *ptr)
{
	t_fdf_obj*const	obj = ptr;

	if (obj == NULL)
		return ;
	smart_free(fdf_obj_manager(), obj->edge);
	smart_free(fdf_obj_manager(), obj->node);
	free(obj);
}

t_fdf_obj	*new_obj(size_t points, size_t edges)
{
	t_fdf_obj*const	obj
		= smart_malloc(fdf_obj_manager(), sizeof(t_fdf_obj), delete_obj);
	size_t			idx;

	if (obj == NULL)
		smart_exit(fdf_obj_manager(), EXIT_FAILURE);
	obj->node = smart_malloc(fdf_obj_manager(), sizeof(t_fdf_point) * points, free);
	obj->edge = smart_malloc(fdf_obj_manager(), sizeof(t_fdf_point **) * edges, free);
	if (obj->node == NULL || obj->edge == NULL)
		smart_exit(fdf_obj_manager(), EXIT_FAILURE);
	obj->cnt_point = points;
	obj->cnt_edge = edges;
	idx = 0;
	while (idx < edges)
	{
		obj->edge[idx]
			= smart_malloc(fdf_obj_manager(), sizeof(t_point3d *) * 2, free);
		if (obj->edge[idx] == NULL)
			smart_exit(fdf_obj_manager(), EXIT_FAILURE);
		obj->edge[idx][0] = NULL;
		obj->edge[idx][1] = NULL;
		++idx;
	}
	return (obj);
}