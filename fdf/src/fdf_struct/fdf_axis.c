/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:03:47 by dowon             #+#    #+#             */
/*   Updated: 2023/06/25 17:48:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_obj/fdf_obj.h"
#include "fdf_struct.h"
#include "../ptr_manager/ptr_manager.h"

t_fdf_obj	*new_axis(const t_vector3 len)
{
	t_fdf_obj*const	axis = new_obj(4, 3);

	axis->node[0] = (t_color_point){{{0.0, 0.0, 0.0},
		my_mlx_rgba(0, 0, 0, 255)}};
	axis->node[1] = (t_color_point){{{len.x, 0.0, 0.0},
		my_mlx_rgba(255, 0, 0, 255)}};
	axis->node[2] = (t_color_point){{{0.0, len.y, 0.0},
		my_mlx_rgba(0, 255, 0, 255)}};
	axis->node[3] = (t_color_point){{{0.0, 0.0, len.z},
		my_mlx_rgba(0, 0, 255, 255)}};
	axis->edge[0][0] = axis->node + 0;
	axis->edge[1][0] = axis->node + 0;
	axis->edge[2][0] = axis->node + 0;
	axis->edge[0][1] = axis->node + 1;
	axis->edge[1][1] = axis->node + 2;
	axis->edge[2][1] = axis->node + 3;
	return (axis);
}
