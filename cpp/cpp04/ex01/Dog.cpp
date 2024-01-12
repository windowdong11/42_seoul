#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog()
	: Animal(), brain(new Brain())
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[Constructor] default" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &rhs)
	: brain(NULL)
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[Constructor] copy" << std::endl;
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "<op> =" << std::endl;
	if (this == &rhs)
	{
		std::cout << "\tnot copied (same object)" << std::endl;
		return *this;
	}
	std::cout << "\tcopied" << std::endl;
	if (this->brain != NULL)
	{
		delete this->brain;
		this->brain = NULL;
	}
	this->brain = new Brain();
	*this->brain = *rhs.brain;
	type = rhs.type;
	std::cout << "rhs brain : " << rhs.brain << std::endl;
	std::cout << "brain after copy : " << this->brain << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "[Destructor]" << std::endl;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = NULL;
}

void Dog::makeSound() const
{
	std::cout << COLOR_GREEN << "Dog" << COLOR_RESET << "{makeSound}" << std::endl;
	std::cout << "\tbark" << std::endl;
}
