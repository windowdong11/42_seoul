#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;
	return 0;
}