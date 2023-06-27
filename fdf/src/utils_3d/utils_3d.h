/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:22:32 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:20:40 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_3D_H
# define UTILS_3D_H

# include "matrix3.h"
# include "matrix4.h"
# include "vector3.h"
# include "vector4.h"
# include "quaternion.h"

/* matrix3 */
t_matrix3	*m3_zero(t_matrix3 *out);
t_matrix3	*m3_identity(t_matrix3 *out);
t_matrix3	*m3_add(t_matrix3 *out,
				const t_matrix3 *m1, const t_matrix3 *m2);
t_matrix3	*m3_multiply(t_matrix3 *out,
				const t_matrix3 *m1, const t_matrix3 *m2);
t_matrix3	*m3_translation(t_matrix3 *out, float x, float y, float z);

t_matrix3	*m3_rotate_x(t_matrix3 *out, float rad);
t_matrix3	*m3_rotate_y(t_matrix3 *out, float rad);
t_matrix3	*m3_rotate_z(t_matrix3 *out, float rad);

t_matrix3	*m3_scaling(t_matrix3 *out, float sx, float sy, float sz);

/* vector3 */
t_vector3	*vector3(t_vector3 *out, float x, float y, float z);
t_vector3	*v3_unit(t_vector3 *out, const t_vector3 *v);
t_vector3	*v3_zero(t_vector3 *out);

t_vector3	*v3_add(t_vector3 *out, const t_vector3 *v1, const t_vector3 *v2);
t_vector3	*v3_negate(t_vector3 *out, const t_vector3 *v);

t_vector3	*v3_pow(t_vector3 *out, const t_vector3 *v, float n);
t_vector3	*v3_div(t_vector3 *out, const t_vector3 *v, float n);

t_vector3	*v3_translate(t_vector3 *out,
				const t_vector3 *v1, const t_vector3 *v2);
t_vector3	*v3_transform(t_vector3 *out,
				const t_vector3 *v, const t_matrix3 *m);

t_vector3	*v3_cross(t_vector3 *out, const t_vector3 *p1, const t_vector3 *p2);
float		v3_dot(const t_vector3 *v1, const t_vector3 *v2);
float		v3_len(const t_vector3 *v);
float		v3_lensq(const t_vector3 *v);

/* quaternion */
// t_quaternion	*matrix3_to_quaternion(t_quaternion *out, const t_matrix3 *m);

#endif