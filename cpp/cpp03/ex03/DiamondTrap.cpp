#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("annon_clap_name"), name("annon")
{
	std::cout << COLOR_BLUE << "diamond " << COLOR_YELLOW << "[Constructor] Default " << name << COLOR_RESET << std::endl;
	health = 100;
	energy = 50;
	damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << COLOR_BLUE << "diamond " << COLOR_YELLOW << "[Constructor] Copy " << name << COLOR_RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this == &other)
		return *this;
	std::cout << COLOR_BLUE << "diamond " << COLOR_MAGENTA << "<op> copy " << other.name << COLOR_RESET << std::endl;
	ClapTrap::operator=(other);
	name = other.name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << COLOR_BLUE << "diamond " << COLOR_YELLOW << "[Destructor] " << name << COLOR_RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	:  ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), name(name)
{
	std::cout << COLOR_BLUE << "diamond " << COLOR_YELLOW << "[Constructor] name : " << name << COLOR_RESET << std::endl;
	health = 100;
	energy = 50;
	damage = 30;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << COLOR_BLUE << "diamond " << "[whoAmI] name: " << name << " clapTrap-name: " << ClapTrap::name << COLOR_RESET << std::endl;
}
