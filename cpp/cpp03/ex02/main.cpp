#include "FragTrap.hpp"

int main()
{
	FragTrap scav("Mario");

	scav.highFiveGuys();
	scav.takeDamage(3);
	scav.attack("Luigi"); //	hp : 20
	scav.beRepaired(3);
	return 0;
}