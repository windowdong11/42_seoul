#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name("annon"), health(10), energy(10), damage(0)
{
	std::cout << COLOR_YELLOW << "[Constructor] Default " << name << COLOR_RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), health(other.health), energy(other.energy), damage(other.damage)
{
	std::cout << COLOR_YELLOW << "[Constructor] Copy " << name << COLOR_RESET << std::endl;
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

// ------ orthodox form end -----

ClapTrap::ClapTrap(const std::string &name)
	: name(name), health(10), energy(10), damage(0)
{
	std::cout << COLOR_YELLOW << "[Constructor] name : " << name << COLOR_RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << COLOR_BLUE << "[method] attack, name : " << name << COLOR_RESET << std::endl;
	if (health == 0 || energy == 0)
		return;
	std::cout << "[attack] claptrap : " << name << " attacks " << target << " with damage " << damage << std::endl;
	--energy;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << COLOR_BLUE << "[method] takeDamage, name : " << name << COLOR_RESET << std::endl;
	if (health == 0)
		return;
	std::cout << "[takeDamage] claptrap : " << name << " takeDamage " << amount << std::endl;
	if (health <= amount)
		health = 0;
	else
		health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << COLOR_BLUE << "[method] beRepaired, name : " << name << COLOR_RESET << std::endl;
	if (health == 0 || energy == 0)
		return;
	std::cout << "[beRepaired] claptrap : " << name << " repair " << amount << std::endl;
	health += amount;
	--energy;
}
