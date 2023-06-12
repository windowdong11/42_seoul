/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:04:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 17:34:53 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_struct.h"
#include "../fdf_obj/fdf_obj.h"

void	fdf_proj(t_fdf	*fdf)
{
	t_fdf_obj*const	obj = copy_fdf_obj(fdf->obj);

	if (fdf->with_axis == 1)
		draw_axis(fdf, &(t_vector3){100.0, 100.0, 100.0});
	v3_add(&fdf->scale, &fdf->scale, &fdf->d_scale);
	v3_add(&fdf->rad, &fdf->rad, &fdf->d_rad);
	v3_add(&fdf->position, &fdf->position, &fdf->d_pos);
	fdf_scale(obj, &fdf->scale);
	fdf_rotate(obj, &fdf->rad);
	fdf_draw_at(fdf->img, obj, fdf->position);
	smart_free(ptr_manager(), obj);
}
