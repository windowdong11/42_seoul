/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:30:59 by dowon             #+#    #+#             */
/*   Updated: 2023/06/08 22:02:44 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX3_H
# define MATRIX3_H

# include "vector3.h"

typedef struct s_matrix3
{
	union
	{
		struct
		{
			float	_11;
			float	_12;
			float	_13;
			float	_21;
			float	_22;
			float	_23;
			float	_31;
			float	_32;
			float	_33;
		};
		float		m[3][3];
		t_vector3	v[3];
	};
}	t_matrix3;

#endif