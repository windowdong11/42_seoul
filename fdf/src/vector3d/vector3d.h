/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:42:09 by dowon             #+#    #+#             */
/*   Updated: 2023/05/28 21:23:22 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

typedef t_vector3d	t_point3d;

/* structor */
t_vector3d	vector3d(double x, double y, double z);
/* len_op */
double		len3d_sq(t_vector3d v);
double		len3d(t_vector3d v);
/* scalar_op */
t_vector3d	pow3d(t_vector3d v, double n);
t_vector3d	div3d(t_vector3d v, double n);
/* vector_op */
t_vector3d	translate3d(t_vector3d v, t_vector3d d);
t_vector3d	transform3d(t_vector3d trans[3], t_vector3d v);
t_vector3d	cross3d(t_vector3d a, t_vector3d b);
double		dot3d(t_vector3d a, t_vector3d b);

#endif