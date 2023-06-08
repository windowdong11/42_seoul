/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:37:04 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:21:47 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_OBJ_H
# define FDF_OBJ_H

# include "../utils_3d/utils_3d.h"
# include <stdlib.h>

typedef struct s_fdf_obj
{
	t_point3d	*point;
	t_point3d	***edge;
	size_t		cnt_point;
	size_t		cnt_edge;
}	t_fdf_obj;

t_fdf_obj	*fdf_rotate_x(t_fdf_obj	*obj, float angle);
t_fdf_obj	*fdf_rotate_y(t_fdf_obj	*obj, float angle);
t_fdf_obj	*fdf_rotate_z(t_fdf_obj	*obj, float angle);

#endif