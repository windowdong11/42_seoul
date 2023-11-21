#include "Zombie.hpp"

int main()
{
	Zombie aa("announcer");
	aa.announce();

	Zombie* bb = newZombie("alloc");
	bb->announce();
	delete bb;

	randomChump("rand");
	return 0;
}