#include "Base.hpp"
#include <iostream>

int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << ">>[" << i << "]<<" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
	}
	return 0;
}