#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {};
Zombie::Zombie(std::string name) : name(name) {}
Zombie::~Zombie() {
	std::cout << "[destructor]" << name << std::endl;
}
void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
