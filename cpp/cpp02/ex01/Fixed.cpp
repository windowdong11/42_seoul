#include "Fixed.hpp"
#include <iostream>

const int Fixed::fraction = 8;

Fixed::Fixed()
	: raw_fixed(0)
{
	std::cout << COLOR_GREEN << "+[Constructor] Default constructor called" << COLOR_RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << COLOR_GREEN << "+[Constructor] Copy constructor called" << COLOR_RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << COLOR_YELLOW << "<op> Copy assignment operator called" << COLOR_RESET << std::endl;
	if (this == &other)
		return (*this);
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << COLOR_RED << "-[Destuctor] Destructor called" << COLOR_RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (raw_fixed);
}

void Fixed::setRawBits(int const raw)
{
	raw_fixed = raw;
}

// ----------------- ex01 -----------------

Fixed::Fixed(const int integer)
	: raw_fixed(integer << fraction)
{
	std::cout << COLOR_GREEN << "+[Constructor] Constructor with param called (param: int)" << COLOR_RESET << std::endl;
}

Fixed::Fixed(const float floating)
	: raw_fixed(roundf(floating * static_cast<float>(1 << fraction)))
{
	std::cout << COLOR_GREEN << "+[Constructor] Constructor with param called (param: float)" << COLOR_RESET << std::endl;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(raw_fixed) / static_cast<float>(1 << fraction);
}

int Fixed::toInt(void) const
{
	if (raw_fixed < 0)
		return -((-raw_fixed) >> fraction);
	return raw_fixed >> fraction;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
