#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap()
{
	std::cout << COLOR_GREEN << "scav " << COLOR_YELLOW << "[Constructor] Default " << name << COLOR_RESET << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << COLOR_GREEN << "scav " << COLOR_YELLOW << "[Constructor] Copy " << name << COLOR_RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
		return *this;
		std::cout << COLOR_GREEN << "scav " << COLOR_MAGENTA << "<op> copy " << other.name << COLOR_RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << COLOR_GREEN << "scav " << COLOR_RED << "[Destructor] " << name << COLOR_RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	std::cout << COLOR_GREEN << "scav " << COLOR_YELLOW << "[Constructor] name : " << name << COLOR_RESET << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}


void ScavTrap::attack(const std::string &target)
{
	if (health == 0 || energy == 0)
		return;
	std::cout << COLOR_GREEN << "scav " << COLOR_RESET << "[attack] : " << name << " attacks " << target << " with damage " << damage << COLOR_RESET << std::endl;
	--energy;
}

void ScavTrap::guardGate()
{
	std::cout << COLOR_GREEN << "scav " << COLOR_RESET << "[guardGate] : " << name << " attacks " << COLOR_RESET << std::endl;
}
