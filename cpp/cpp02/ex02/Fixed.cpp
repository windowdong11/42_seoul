#include "Fixed.hpp"
#include <iostream>

const int Fixed::fraction = 8;

Fixed::Fixed()
	: raw_fixed(0)
{
	if (PRINT_STRUCTOR_LOGS)
		std::cout << COLOR_GREEN << "+[Constructor] Default constructor called" << COLOR_RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	if (PRINT_STRUCTOR_LOGS)
		std::cout << COLOR_GREEN << "+[Constructor] Copy constructor called" << COLOR_RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (PRINT_STRUCTOR_LOGS)
		std::cout << COLOR_YELLOW << "<op> Copy assignment operator called" << COLOR_RESET << std::endl;
	if (this == &other)
		return (*this);
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	if (PRINT_STRUCTOR_LOGS)
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
	if (PRINT_STRUCTOR_LOGS)
		std::cout << COLOR_GREEN << "+[Constructor] Constructor with param called (param: int)" << COLOR_RESET << std::endl;
}

Fixed::Fixed(const float floating)
	: raw_fixed(roundf(floating * static_cast<float>(1 << fraction)))
{
	if (PRINT_STRUCTOR_LOGS)
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

// ----------------- ex02 -----------------

bool Fixed::operator>(const Fixed& rhs) const
{
	return raw_fixed > rhs.raw_fixed;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return raw_fixed < rhs.raw_fixed;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return raw_fixed >= rhs.raw_fixed;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return raw_fixed <= rhs.raw_fixed;
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return raw_fixed == rhs.raw_fixed;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return raw_fixed != rhs.raw_fixed;
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return raw_fixed + rhs.raw_fixed;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return raw_fixed - rhs.raw_fixed;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits((static_cast<long long>(raw_fixed) * rhs.raw_fixed) >> fraction);
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(static_cast<long long>(raw_fixed) * 256 / rhs.raw_fixed);
	return result;
}

Fixed& Fixed::operator++()
{
	++this->raw_fixed;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copied(*this);
	++this->raw_fixed;
	return copied;
}

Fixed& Fixed::operator--()
{
	--this->raw_fixed;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed copied(*this);
	--this->raw_fixed;
	return copied;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}
