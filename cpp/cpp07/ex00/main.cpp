#include "whatever.hpp"
#include <iostream>
#include <string>

#ifndef TEST_CONST_SWAP
#define TEST_CONST_SWAP 0
#endif

int main()
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << '\n';

	std::cout << ">>non-const<<\n";
	int n1 = 1, n2 = 2;
	std::cout << "[before]\n";
	std::cout << "n1 : " << n1 << ", n2 : " << n2 << '\n';
	::swap(n1, n2);
	std::cout << "[after]\n";
	std::cout << "n1 : " << n1 << ", n2 : " << n2 << '\n';

	int *p1 = &n1, *p2 = &n2;
	std::cout << "[before]\n";
	std::cout << "p1 : " << p1 << ", p2 : " << p2 << '\n';
	::swap(p1, p2);
	std::cout << "[after]\n";
	std::cout << "p1 : " << p1 << ", p2 : " << p2 << '\n';

	int &r1 = n1, &r2 = n2;
	std::cout << "[before]\n";
	std::cout << "r1 : " << r1 << ", r2 : " << r2 << '\n';
	::swap(r1, r2);
	std::cout << "[after]\n";
	std::cout << "r1 : " << r1 << ", r2 : " << r2 << '\n';
/* const */
#if TEST_CONST_SWAP
	std::cout << ">>const<<\n";

	const int cn1 = 1, cn2 = 2;
	std::cout << "[before]\n";
	std::cout << "cn1 : " << cn1 << ", cn2 : " << cn2 << '\n';
	::swap(cn1, cn2);
	std::cout << "[after]\n";
	std::cout << "cn1 : " << cn1 << ", cn2 : " << cn2 << '\n';

	const int *cp1 = &cn1, *cp2 = &cn2;
	std::cout << "[before]\n";
	std::cout << "cp1 : " << cp1 << ", cp2 : " << cp2 << '\n';
	::swap(cp1, cp2);
	std::cout << "[after]\n";
	std::cout << "cp1 : " << cp1 << ", cp2 : " << cp2 << '\n';

	const int &cr1 = cn1, &cr2 = cn2;
	std::cout << "[before]\n";
	std::cout << "cr1 : " << cr1 << ", cr2 : " << cr2 << '\n';
	::swap(cr1, cr2);
	std::cout << "[after]\n";
	std::cout << "cr1 : " << cr1 << ", cr2 : " << cr2 << '\n';
#endif
}