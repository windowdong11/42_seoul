#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap dia("Mario");

	std::cout << std::endl;
	dia.highFiveGuys();
	std::cout << std::endl;
	dia.takeDamage(3);
	std::cout << std::endl;
	dia.attack("Luigi"); //	hp : 20
	std::cout << std::endl;
	dia.beRepaired(3);
	std::cout << std::endl;
	dia.whoAmI();
	std::cout << std::endl;
	return 0;
}