#include "Point.hpp"

Point::Point()
	:x(0), y(0)
{}

Point::Point(const Point& other)
	:x(other.x), y(other.y)
{}

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;
	// copy something
	return *this;
}

Point::~Point()
{}

Point::Point(const float x, const float y)
	:x(x), y(y)
{
}

Point::Point(const Fixed& x, const Fixed& y)
	:x(x), y(y)
{}

Fixed Point::cross(const Point &other) const
{
	return this->x * other.y - this->y * other.x;
}

Point Point::operator-(const Point &other) const
{
	return Point(x - other.x, y - other.y);
}
