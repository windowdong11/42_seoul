/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:05:26 by dowon             #+#    #+#             */
/*   Updated: 2023/06/23 23:29:26 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

t_fdf_obj	*dup_fdf_obj(const t_fdf_obj *src)
{
	t_fdf_obj*const	obj = new_obj(src->cnt_node, src->cnt_edge);
	size_t			idx;

	idx = 0;
	while (idx < src->cnt_node)
	{
		obj->node[idx] = src->node[idx];
		++idx;
	}
	idx = 0;
	while (idx < src->cnt_edge)
	{
		obj->edge[idx][0] = obj->node + (src->edge[idx][0] - src->node);
		obj->edge[idx][1] = obj->node + (src->edge[idx][1] - src->node);
		++idx;
	}
	return (obj);
}

void	copy_fdf_obj(t_fdf_obj *dest, const t_fdf_obj *src)
{
	size_t			idx;

	idx = 0;
	while (idx < src->cnt_node)
	{
		dest->node[idx] = src->node[idx];
		++idx;
	}
	idx = 0;
	while (idx < src->cnt_edge)
	{
		dest->edge[idx][0] = dest->node + (src->edge[idx][0] - src->node);
		dest->edge[idx][1] = dest->node + (src->edge[idx][1] - src->node);
		++idx;
	}
}
