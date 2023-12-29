#ifndef POINT_HPP
# define POINT_HPP

/* include headers */
#include "Fixed.hpp"

/* code */
class Point
{
private:
	const Fixed x, y;
public:
	Point();
	Point(const Point& other);
	Point &operator=(const Point& other);
	~Point();
	Point(float x, float y);
	Point(const Fixed& x, const Fixed& y);
	Fixed cross(const Point& other) const;
	Point operator-(const Point& other) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif