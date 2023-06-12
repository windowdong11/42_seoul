mat4 RotationMatrix = quaternion::toMat4(quaternion);
mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;



#include "scalar_constants.hpp"

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T angle(qua<T, Q> const& x)
	{
		if (abs(x.w) > cos_one_over_two<T>())
		{
			T const a = asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<T>(2);
			if(x.w < static_cast<T>(0))
				return pi<T>() * static_cast<T>(2) - a;
			return a;
		}

		return acos(x.w) * static_cast<T>(2);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> axis(qua<T, Q> const& x)
	{
		T const tmp1 = static_cast<T>(1) - x.w * x.w;
		if(tmp1 <= static_cast<T>(0))
			return vec<3, T, Q>(0, 0, 1);
		T const tmp2 = static_cast<T>(1) / sqrt(tmp1);
		return vec<3, T, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER qua<T, Q> angleAxis(T const& angle, vec<3, T, Q> const& v)
	{
		T const a(angle);
		T const s = glm::sin(a * static_cast<T>(0.5));

		return qua<T, Q>(glm::cos(a * static_cast<T>(0.5)), v * s);
	}
}//namespace glm

template <typename T, qualifier Q>
GLM_FUNC_QUALIFIER T roll(qua<T, Q> const &q)
{
	T const y = static_cast<T>(2) * (q.x * q.y + q.w * q.z);
	T const x = q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z;

	if (all(equal(vec<2, T, Q>(x, y), vec<2, T, Q>(0), epsilon<T>()))) // avoid atan2(0,0) - handle singularity - Matiis
		return static_cast<T>(0);

	return static_cast<T>(atan(y, x));
}

template <typename T, qualifier Q>
GLM_FUNC_QUALIFIER T pitch(qua<T, Q> const &q)
{
	// return T(atan(T(2) * (q.y * q.z + q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z));
	T const y = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
	T const x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

	if (all(equal(vec<2, T, Q>(x, y), vec<2, T, Q>(0), epsilon<T>()))) // avoid atan2(0,0) - handle singularity - Matiis
		return static_cast<T>(static_cast<T>(2) * atan(q.x, q.w));

	return static_cast<T>(atan(y, x));
}

template <typename T, qualifier Q>
GLM_FUNC_QUALIFIER T yaw(qua<T, Q> const &q)
{
	return asin(clamp(static_cast<T>(-2) * (q.x * q.z - q.w * q.y), static_cast<T>(-1), static_cast<T>(1)));
}
GLM_FUNC_QUALIFIER vec<3, T, Q> eulerAngles(qua<T, Q> const &x)
{
	return vec<3, T, Q>(pitch(x), yaw(x), roll(x));
}

template <typename T, qualifier Q>
GLM_FUNC_QUALIFIER mat<3, 3, T, Q> mat3_cast(qua<T, Q> const &q)
{
	mat<3, 3, T, Q> Result(T(1));
	T qxx(q.x * q.x);
	T qyy(q.y * q.y);
	T qzz(q.z * q.z);
	T qxz(q.x * q.z);
	T qxy(q.x * q.y);
	T qyz(q.y * q.z);
	T qwx(q.w * q.x);
	T qwy(q.w * q.y);
	T qwz(q.w * q.z);

	Result[0][0] = T(1) - T(2) * (qyy + qzz);
	Result[0][1] = T(2) * (qxy + qwz);
	Result[0][2] = T(2) * (qxz - qwy);

	Result[1][0] = T(2) * (qxy - qwz);
	Result[1][1] = T(1) - T(2) * (qxx + qzz);
	Result[1][2] = T(2) * (qyz + qwx);

	Result[2][0] = T(2) * (qxz + qwy);
	Result[2][1] = T(2) * (qyz - qwx);
	Result[2][2] = T(1) - T(2) * (qxx + qyy);
	return Result;
}

template<typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(T const& s)
{
	this->value[0] = col_type(s, 0, 0, 0);
	this->value[1] = col_type(0, s, 0, 0);
	this->value[2] = col_type(0, 0, s, 0);
	this->value[3] = col_type(0, 0, 0, s);
}

template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<3, 3, T, Q> const& m)
	{
			this->value[0] = col_type(m[0], 0);
			this->value[1] = col_type(m[1], 0);
			this->value[2] = col_type(m[2], 0);
			this->value[3] = col_type(0, 0, 0, 1);
	}

template <typename T, qualifier Q>
GLM_FUNC_QUALIFIER mat<4, 4, T, Q> mat4_cast(qua<T, Q> const &q)
{
	return mat<4, 4, T, Q>(mat3_cast(q));
}
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> toMat4(
		qua<T, Q> const& x){return mat4_cast(x);}