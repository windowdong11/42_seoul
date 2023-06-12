/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:03:47 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 18:40:31 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_obj/fdf_obj.h"
#include "fdf_struct.h"

void	draw_axis(t_fdf *fdf, const t_vector3 *len)
{
	t_fdf_obj*const	axis = new_obj(4, 3);

	axis->node[0] = (t_color_point){{{0.0, 0.0, 0.0},
		my_mlx_rgba(0, 0, 0, 255)}};
	axis->node[1] = (t_color_point){{{len->x, 0.0, 0.0},
		my_mlx_rgba(255, 0, 0, 255)}};
	axis->node[2] = (t_color_point){{{0.0, len->y, 0.0},
		my_mlx_rgba(0, 255, 0, 255)}};
	axis->node[3] = (t_color_point){{{0.0, 0.0, len->z},
		my_mlx_rgba(0, 0, 255, 255)}};
	axis->edge[0][0] = axis->node + 0;
	axis->edge[1][0] = axis->node + 0;
	axis->edge[2][0] = axis->node + 0;
	axis->edge[0][1] = axis->node + 1;
	axis->edge[1][1] = axis->node + 2;
	axis->edge[2][1] = axis->node + 3;
	v3_add(&fdf->scale, &fdf->scale, &fdf->d_scale);
	v3_add(&fdf->rad, &fdf->rad, &fdf->d_rad);
	v3_add(&fdf->position, &fdf->position, &fdf->d_pos);
	fdf_scale(axis, &fdf->scale);
	// fdf_rotate(axis, &fdf->rad);
	fdf_draw_at(fdf->img, axis, fdf->position);
	smart_free(ptr_manager(), axis);
	t_fdf_obj*const axis2 = new_obj(4, 3);

	axis2->node[0] = (t_color_point){{{0.0, 0.0, 0.0},
		my_mlx_rgba(0, 0, 0, 255)}};
	axis2->node[1] = (t_color_point){{{len->x, 0.0, 0.0},
		my_mlx_rgba(255, 0, 0, 255)}};
	axis2->node[2] = (t_color_point){{{0.0, len->y, 0.0},
		my_mlx_rgba(0, 255, 0, 255)}};
	axis2->node[3] = (t_color_point){{{0.0, 0.0, len->z},
		my_mlx_rgba(0, 0, 255, 255)}};
	axis2->edge[0][0] = axis2->node + 0;
	axis2->edge[1][0] = axis2->node + 0;
	axis2->edge[2][0] = axis2->node + 0;
	axis2->edge[0][1] = axis2->node + 1;
	axis2->edge[1][1] = axis2->node + 2;
	axis2->edge[2][1] = axis2->node + 3;
	v3_add(&fdf->scale, &fdf->scale, &fdf->d_scale);
	v3_add(&fdf->rad, &fdf->rad, &fdf->d_rad);
	v3_add(&fdf->position, &fdf->position, &fdf->d_pos);
	fdf_scale(axis2, &fdf->scale);
	fdf_rotate(axis2, &fdf->rad);
	fdf_draw_at(fdf->img, axis2, fdf->position);
	smart_free(ptr_manager(), axis2);
}
