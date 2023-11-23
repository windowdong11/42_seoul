#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie aa("announcer");
	aa.announce();

	int count;
	std::cout << "zombie count : ";
	std::cin >> count;
	Zombie* alloc = zombieHorde(count, "alloc");
	for (int i = 0; i < count; ++i)
	{
		alloc[i].announce();
	}
	delete[] alloc;
	return 0;
}