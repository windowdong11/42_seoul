/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:43:24 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 22:45:19 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"

t_fdf_obj	*fdf_translate(t_fdf_obj *obj, t_vector3 v)
{
	size_t		idx;

	idx = 0;
	while (idx < obj->cnt_point)
	{
		v3_translate(&obj->node[idx].point, &obj->node[idx].point, &v);
		++idx;
	}
	return (obj);
}
