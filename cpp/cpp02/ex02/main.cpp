#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(5.05f) / Fixed(2));

	std::cout << "expect : 0, value : "<< a << std::endl;
	std::cout << "expect : 0.00390625, value : "<< ++a << std::endl;
	std::cout << "expect : 0.00390625, value : "<< a << std::endl;
	std::cout << "expect : 0.00390625, value : "<< a++ << std::endl;
	std::cout << "expect : 0.0078125, value : "<< a << std::endl;
	std::cout << "sub" << std::endl;
	std::cout << "expect : 0.00390625, value : "<< --a << std::endl;
	std::cout << "expect : 0.00390625, value : "<< a << std::endl;
	std::cout << "expect : 0.00390625, value : "<< a-- << std::endl;
	std::cout << "expect : 0, value : "<< a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << c << std::endl;
	std::cout << "Expect floating point exception (divide by zero)" << std::endl;
	std::cout << (Fixed(0) / Fixed(0)) << std::endl;
	return 0;
}