#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog()
	: Animal()
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[Constructor] default" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& rhs)
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[Constructor] copy" << std::endl;
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "<op> =" << std::endl;
	if (this == &rhs)
		return *this;
	type = rhs.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[Destructor]" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

void Dog::makeSound() const
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[makeSound] bark" << std::endl;
}
