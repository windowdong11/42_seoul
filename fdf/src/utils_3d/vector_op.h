/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:22:32 by dowon             #+#    #+#             */
/*   Updated: 2023/06/06 18:38:30 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OP_H
# define VECTOR_OP_H

# include "matrix3.h"
# include "matrix4.h"
# include "vector3.h"
# include "vector4.h"
# include "quaternion.h"

/* matrix3 */
t_matrix3		*m3_multiply(t_matrix3 *out,
					const t_matrix3 *m1, const t_matrix3 *m2);
t_matrix3		*m3_translation(t_matrix3 *out, float x, float y, float z);
t_matrix3		*m3_rotationX(t_matrix3 *out, float Angle);
t_matrix3		*m3_rotationY(t_matrix3 *out, float Angle);
t_matrix3		*m3_rotationZ(t_matrix3 *out, float Angle);
t_matrix3		*m3_rotation_quaternion(t_matrix3 *out, const t_quaternion *pQ);
t_matrix3		*m3_scaling(t_matrix3 *out, float sx, float sy, float sz);
t_matrix3		*m3_affinetransform(t_matrix3 *out, float Scaling, const t_vector3 *pRotationCenter, const t_quaternion *pRotation, const t_vector3 *pTranslation);
/* vector3 */
t_vector3		*v3_cross(t_vector3 *out, const t_vector3 *v1, const t_vector3 *v2);
float			v3_dot(const t_vector3 *v1, const t_vector3 *v2);
t_vector4		*v3_transform(t_vector4 *out, const t_vector3 *v, const t_matrix3 *m);
/* quaternion */
t_quaternion	*matrix3_to_quaternion(t_quaternion *out, const t_matrix3 *m);

#endif