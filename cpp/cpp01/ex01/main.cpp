#include "Zombie.hpp"

int main()
{
	Zombie aa("announcer");
	aa.announce();

	const int count = 5;
	Zombie* alloc = zombieHorde(count, "alloc");
	for (int i = 0; i < count; ++i)
	{
		alloc[i].announce();
	}
	delete[] alloc;
	return 0;
}