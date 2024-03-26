#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	static bool is_seeded = false;
	if (is_seeded == false)
	{
		std::srand(std::time(0));
		is_seeded = true;
	}
	int random = std::rand() % 3;
	std::cout << "generate: ";
	switch (random)
	{
	case 0:
		// std::cout << "A" << std::endl;
		return new A();
		break;
	case 1:
		// std::cout << "B" << std::endl;
		return new B();
		break;
	case 2:
		// std::cout << "C" << std::endl;
		return new C();
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{
	}
}
