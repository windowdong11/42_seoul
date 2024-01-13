#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat()
	: Animal(), brain(new Brain())
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "[Constructor] default" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &rhs)
	: brain(new Brain())
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "[Constructor] copy" << std::endl;
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "<op> =" << std::endl;
	if (this == &rhs)
	{
		std::cout << "not copied (same object)" << std::endl;
		return *this;
	}
	std::cout << "\tcopy" << std::endl;
	Animal::operator=(rhs);
	*this->brain = *rhs.brain;
	std::cout << "rhs brain : " << rhs.brain << std::endl;
	std::cout << "brain after copy : " << this->brain << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "[Destructor]" << std::endl;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = NULL;
}

void Cat::makeSound() const
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "{makeSound}" << std::endl;
	std::cout << "\tmeow" << std::endl;
}
