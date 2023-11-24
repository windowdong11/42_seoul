#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
	: type(type)
{
}

Weapon::~Weapon()
{
}

std::string Weapon::getType()
{
	return type;
}
void Weapon::setType(std::string type)
{
	this->type = type;
}