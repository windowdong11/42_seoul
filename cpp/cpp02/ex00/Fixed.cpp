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
