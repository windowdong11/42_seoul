/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:42:09 by dowon             #+#    #+#             */
/*   Updated: 2023/05/27 22:50:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

typedef struct s_vector3d
{
	int	x;
	int	y;
	int	z;
}	t_vector3d;

void	pow3d(t_vector3d v, int n);
void	translate3d(t_vector3d v, t_vector3d d);
void	transform3d(t_vector3d trans[3], t_vector3d v);
void	cross3d(t_vector3d a, t_vector3d b);
void	dot3d(t_vector3d a, t_vector3d b);
t_vector3d	normalize(const t_vector3d*const v)
{
	return ((t_vector3d){v->x, v->y, v->z});
}

#endif