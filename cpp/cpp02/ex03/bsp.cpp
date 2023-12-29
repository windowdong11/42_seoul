#include "Point.hpp"
#include <iostream>

/*
@return {1} if point is inside of triangle.
@return {0} if point is outside of triangle or the point is on edge or vertex.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Fixed c1 = (a - b).cross(point - b);
	const Fixed c2 = (b - c).cross(point - c);
	const Fixed c3 = (c - a).cross(point - a);
	return (
		(c1 > 0 && c2 > 0 && c3 > 0)
		|| (c1 < 0 && c2 < 0 && c3 < 0)
	);
}