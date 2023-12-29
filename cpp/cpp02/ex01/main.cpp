#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed const e(0.001953125f);
	Fixed const f(-0.001953125f);
	Fixed const g(-0.5f);
	Fixed const h(-1.5f);

	std::cout << "[Fixed]" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "g: " << g << std::endl;
	std::cout << "h: " << h << std::endl;

	std::cout << "[To Int]" << std::endl;
	std::cout << "a: " << a.toInt() << std::endl;
	std::cout << "b: " << b.toInt() << std::endl;
	std::cout << "c: " << c.toInt() << std::endl;
	std::cout << "d: " << d.toInt() << std::endl;
	std::cout << "e: " << e.toInt() << std::endl;
	std::cout << "f: " << f.toInt() << std::endl;
	std::cout << "g: " << g.toInt() << std::endl;
	std::cout << "h: " << h.toInt() << std::endl;
	std::bitset<32> bit(1 << 7);
	std::cout << bit;
	return 0;
}