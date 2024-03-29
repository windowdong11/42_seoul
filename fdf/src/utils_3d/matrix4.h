/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:31:53 by dowon             #+#    #+#             */
/*   Updated: 2023/06/13 14:36:48 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4_H
# define MATRIX4_H

# include "vector4.h"

typedef struct s_matrix4
{
	union
	{
		struct
		{
			float	_11;
			float	_12;
			float	_13;
			float	_14;
			float	_21;
			float	_22;
			float	_23;
			float	_24;
			float	_31;
			float	_32;
			float	_33;
			float	_34;
			float	_41;
			float	_42;
			float	_43;
			float	_44;
		};
		float		m[4][4];
		t_vector4	v[4];
	};
}	t_matrix4;

#endif