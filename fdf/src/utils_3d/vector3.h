/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:42:09 by dowon             #+#    #+#             */
/*   Updated: 2023/06/05 21:44:10 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

# include "matrix3.h"
# include "matrix4.h"

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_vector4
{
	float	x;
	float	y;
	float	z;
  	float	w;
}	t_vector4;

typedef t_vector3	t_point3d;

typedef struct s_edge3d
{
	t_point3d	v1;
	t_point3d	v2;
}	t_edge3d;

/* structor */
t_vector3	vector3d(float x, float y, float z);
/* len_op */
float		len3d_sq(t_vector3 v);
float		len3d(t_vector3 v);
/* scalar_op */
t_vector3	pow3d(t_vector3 v, float n);
t_vector3	div3d(t_vector3 v, float n);
/* vector_op */
t_vector3	translate3d(t_vector3 v, t_vector3 d);
t_vector3	transform3d(t_vector3 trans[3], t_vector3 v);
t_vector4* transform3d(t_vector4 *pOut, const t_vector3 *pV, const t_matrix3 *pM);
t_vector3*	cross3d(t_vector3 *pOut, const t_vector3 *p1, const t_vector3 *p2);
float		dot3d(const t_vector3 *p1, const t_vector3 *p2);

#endif