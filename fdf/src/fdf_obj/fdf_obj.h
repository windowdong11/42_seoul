/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:37:04 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 22:50:31 by dowon            ###   ########.fr       */
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

typedef struct s_fdf_obj
{
	t_color_point	*node;
	t_color_point	***edge;
	size_t			cnt_point;
	size_t			cnt_edge;
}	t_fdf_obj;

void			fdf_draw(mlx_image_t *img, t_fdf_obj *obj);
void			fdf_draw_at(mlx_image_t *img, t_fdf_obj *obj, t_vector3 at);
t_fdf_obj		*fdf_rotate_x(t_fdf_obj	*obj, float rad);
t_fdf_obj		*fdf_rotate_y(t_fdf_obj	*obj, float rad);
t_fdf_obj		*fdf_rotate_z(t_fdf_obj	*obj, float rad);
t_fdf_obj		*fdf_translate(t_fdf_obj *obj, t_vector3 v);

t_smart_manager	*fdf_obj_manager(void);
void			delete_obj(void *ptr);
t_fdf_obj		*new_obj(size_t points, size_t edges);

#endif