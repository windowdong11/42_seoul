/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:42:09 by dowon             #+#    #+#             */
/*   Updated: 2023/06/09 17:17:53 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "matrix3.h"
# include "matrix4.h"

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef t_vector3	t_point3d;

typedef struct s_edge3d
{
	t_point3d	v1;
	t_point3d	v2;
}	t_edge3d;

#endif