#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: health(10), energy(10), damage(0), name("annon")
{}

ClapTrap::ClapTrap(const ClapTrap& other)
	: health(other.health), energy(other.energy), damage(other.damage), name(other.name)
{
	std::cout << COLOR_YELLOW << "[Constructor] " << name << COLOR_RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return *this;
	std::cout << COLOR_MAGENTA << "<op> copy " << other.name << COLOR_RESET << std::endl;
	health = other.health;
	energy = other.energy;
	damage = other.damage;
	name = other.name;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << COLOR_RED << "[Destructor] " << name << COLOR_RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: health(10), energy(10), damage(0), name(name)
{}

void ClapTrap::attack(const std::string& target)
{
	if (health <= 0 || energy <= 0)
		return;
	std::cout << "[attack] claptrap : " << name << " attacks " << target << " with damage " << damage << std::endl;
	--energy;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (health <= 0)
		return;
	std::cout << "[takeDamage] claptrap : " << name << " takeDamage " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health <= 0 || energy <= 0)
		return;
	std::cout << "[beRepaired] claptrap : " << name << " repair " << amount << std::endl;
	--energy;
}
