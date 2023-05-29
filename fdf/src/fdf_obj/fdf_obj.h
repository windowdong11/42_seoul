/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:37:04 by dowon             #+#    #+#             */
/*   Updated: 2023/05/29 19:39:55 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_OBJ_H
# define FDF_OBJ_H

# include "../vector3d/vector3d.h"

typedef struct s_fdf_obj
{
	t_point3d	*points;
	t_edge3d	*edges;
}	t_fdf_obj;

#endif