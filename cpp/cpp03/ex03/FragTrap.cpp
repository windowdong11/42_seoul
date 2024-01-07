#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap()
{
	std::cout << COLOR_CYAN << "frag " << COLOR_YELLOW << "[Constructor] Default " << name << COLOR_RESET << std::endl;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << COLOR_CYAN << "frag " << COLOR_YELLOW << "[Constructor] Copy " << name << COLOR_RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << COLOR_CYAN << "frag " << COLOR_YELLOW << "[Destructor] " << name << COLOR_RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	std::cout << COLOR_CYAN << "frag " << COLOR_YELLOW << "[Constructor] name : " << name << COLOR_RESET << std::endl;
	health = 100;
	energy = 100;
	damage = 30;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << COLOR_CYAN << "frag " << COLOR_RESET << "[highFiveGuys!!!!] name : " << name << COLOR_RESET << std::endl;
}
