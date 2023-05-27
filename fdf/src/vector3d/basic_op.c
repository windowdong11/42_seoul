#include "vector3d.h"

t_vector3d	pow3d(t_vector3d v, int n)
{
	return ((t_vector3d){
		v.x * n, v.y * n, v.z * n
	});
}

t_vector3d	translate3d(t_vector3d v, t_vector3d d)
{
	return ((t_vector3d){
		v.x + d.x, v.y + d.y, v.z + d.z
	});
}

t_vector3d	transform3d(t_vector3d trans[3], t_vector3d v)
{
	return ((t_vector3d){
		v.x *= trans[0].x + trans[0].y + trans[0].z,
		v.y *= trans[1].x + trans[1].y + trans[1].z,
		v.z *= trans[2].x + trans[2].y + trans[2].z
	});
}

t_vector3d	cross3d(t_vector3d a, t_vector3d b)
{
	return ((t_vector3d){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	});
}

t_vector3d	dot3d(t_vector3d a, t_vector3d b)
{
	return ((t_vector3d){
		a.x + b.
	});
}
