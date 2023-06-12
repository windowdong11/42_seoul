/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:00:01 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 17:33:54 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include <MLX42/MLX42.h>
# include "../utils_3d/utils_3d.h"
# include "../fdf_obj/fdf_obj.h"

typedef struct s_fdf
{
	int			is_updated;
	int			with_axis;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fdf_obj	*obj;
	t_vector3	position;
	t_vector3	rad;
	t_vector3	scale;
	t_vector3	d_pos;
	t_vector3	d_rad;
	t_vector3	d_scale;
	t_vector3	max_dpos;
	t_vector3	max_drad;
	t_vector3	max_dscale;
}	t_fdf;

t_fdf	*new_fdf(int32_t w, int32_t h, const char *title, bool resize);
void	delete_fdf(void *ptr);

void	fdf_proj(t_fdf	*fdf);
void	draw_axis(t_fdf *fdf, const t_vector3 *len);

#endif