#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {};
Zombie::Zombie(std::string name) : name(name) {}
Zombie::~Zombie() {
	std::cout << "[destructor]" << name << std::endl;
}
void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
