#include "fdf/src/utils_3d/utils_3d.h"
#include <math.h>
t_quaternion angleAxis(float angle, t_vector3 v)
{
	float s = sin(angle * 0.5f);
	t_quaternion	q;

	q.w = cosf(angle * 0.5f);
	v3_pow(&v, &v, s);
	q.x = v.x;
	q.y = v.y;
	q.z = v.z;
	return q;
}

t_matrix3	*m3_copy(t_matrix3 *out, const t_matrix3 *m3)
{
	out->v[0] = m3->v[0];
	out->v[1] = m3->v[1];
	out->v[2] = m3->v[2];
	return (out);
}

t_matrix3 *m3_diagonal(t_matrix3 *out, const t_matrix3 *m3, float value)
{
	if (m3 != out)
		m3_copy(out, m3);
	out->_11 = value;
	out->_22 = value;
	out->_33 = value;
	return (m3);
}

t_matrix3	mat3_cast(t_quaternion q)
{
	t_matrix3	res;
	const float	p[4][3] = {
	{q.x * q.x, q.x * q.y, q.x * q.z},
	{0, q.y * q.y, q.y * q.z},
	{0, 0, q.z * q.z},
	{q.w * q.x, q.w * q.y, q.w * q.z}
	};

	m3_identity(&res);
	res.m[0][0] = 1.0f - 2.0f * (p[1][1] + p[2][2]);
	res.m[0][1] = 2.0f * (p[0][1] + p[3][2]);
	res.m[0][2] = 2.0f * (p[0][2] - p[3][1]);

	res.m[1][0] = 2.0f * (p[0][1] - p[3][2]);
	res.m[1][1] = 1.0f - 2.0f * (p[0][0] + p[2][2]);
	res.m[1][2] = 2.0f * (p[1][2] + p[3][0]);

	res.m[2][0] = 2.0f * (p[0][2] + p[3][1]);
	res.m[2][1] = 2.0f * (p[1][2] - p[3][0]);
	res.m[2][2] = 1.0f - 2.0f * (p[0][0] + p[1][1]);
	return (res);
}

t_vector4	v3_to_v4(t_vector3 v3, float w)
{
	t_vector4	v4;

	v4.x = v3.x;
	v4.y = v3.y;
	v4.z = v3.z;
	v4.w = w;
	return (v4);
}

t_vector4	*vector4(t_vector4 *out, float elem[4])
{
	out->x = elem[0];
	out->x = elem[0];
	out->y = elem[0];
	out->z = elem[0];
}

t_matrix4	mat3_to_mat4(t_matrix3 m)
{
	t_matrix4	res;

	res.v[0] = v3_to_v4(m.v[0], 0);
	res.v[1] = v3_to_v4(m.v[1], 0);
	res.v[2] = v3_to_v4(m.v[2], 0);
	vector4(&res.v[3], (float [4]){0, 0, 0, 1});
	return (res);
}

t_matrix4	quarternion_to_m4(t_quaternion q)
{
	return (mat3_to_mat4(mat3_cast(q)));
}

void rotate_x(t_vector4 *v4, float angle)
{
	t_quaternion	q = angleAxis(angle, (t_vector3){1, 0, 0});
	t_matrix4 RotationMatrix = quarternion_to_m4(q);
	m4_pow_v4(RotationMatrix, v4);
}
void rotate_y(float angle)
{
	t_quaternion	q = angleAxis(angle, (t_vector3){0, 1, 0});
	t_matrix4 RotationMatrix = quarternion_to_m4(q);
}
void rotate_z(float angle)
{
	t_quaternion	q = angleAxis(angle, (t_vector3){0, 0, 1});
	t_matrix4 RotationMatrix = quarternion_to_m4(q);
}