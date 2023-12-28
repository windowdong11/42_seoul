#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(5.05f) / Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << c << std::endl;
	std::cout << (Fixed(0) / Fixed(0)) << std::endl;
	return 0;
}