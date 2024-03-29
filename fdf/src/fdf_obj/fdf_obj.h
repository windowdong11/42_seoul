/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:37:04 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 22:37:10 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_OBJ_H
# define FDF_OBJ_H

# include <stdlib.h>
# include <MLX42/MLX42.h>
# include <smart_ptr.h>
# include "../utils_3d/utils_3d.h"
# include "../utils/colors.h"
# include "../mlx_utils/mlx_utils.h"

typedef t_color_point*	t_fdf_node;
typedef t_fdf_node**	t_fdf_edge;
typedef struct s_fdf_obj
{
	t_fdf_node	node;
	t_fdf_edge	edge;
	size_t		cnt_node;
	size_t		cnt_edge;
	size_t		width_x;
	size_t		length_y;
	float		max_depth_z;
	float		min_depth_z;
}	t_fdf_obj;

t_fdf_obj		*dup_fdf_obj(const t_fdf_obj *src);
void			copy_fdf_obj(t_fdf_obj *dest, const t_fdf_obj *src);
void			fdf_draw(mlx_image_t *img, t_fdf_obj *obj);
void			fdf_draw_at(mlx_image_t *img, t_fdf_obj *obj, t_vector3 at);
t_fdf_obj		*fdf_rotate(t_fdf_obj *obj, const t_vector3 *rotate);
t_fdf_obj		*fdf_rotate_rev(t_fdf_obj	*obj, const t_vector3 *rotate);
t_fdf_obj		*fdf_rotate_x(t_fdf_obj	*obj, float rad);
t_fdf_obj		*fdf_rotate_y(t_fdf_obj	*obj, float rad);
t_fdf_obj		*fdf_rotate_z(t_fdf_obj	*obj, float rad);
t_fdf_obj		*fdf_translate(t_fdf_obj *obj, t_vector3 v);
t_fdf_obj		*fdf_scale(t_fdf_obj *obj, const t_vector3 *scale);
t_fdf_obj		*fdf_scale_rev(t_fdf_obj *obj, const t_vector3 *scale);
t_fdf_obj		*fdf_scale_x(t_fdf_obj *obj, float sx);
t_fdf_obj		*fdf_scale_y(t_fdf_obj *obj, float sy);
t_fdf_obj		*fdf_scale_z(t_fdf_obj *obj, float sz);

void			delete_obj(void *ptr);
t_fdf_obj		*new_obj(size_t points, size_t edges);

#endif