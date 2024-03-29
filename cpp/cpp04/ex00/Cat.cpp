#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat()
	: Animal()
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "[Constructor] default" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &rhs)
	: Animal(rhs)
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "[Constructor] copy" << std::endl;
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "<op> =" << std::endl;
	if (this == &rhs)
	{
		std::cout << "\tnot copied (same object)" << std::endl;
		return *this;
	}
	std::cout << "\tcopy" << std::endl;
	Animal::operator=(rhs);
	return *this;
}

Cat::~Cat()
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "[Destructor]" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << COLOR_YELLOW << "Cat" << COLOR_RESET << "{makeSound}" << std::endl;
	std::cout << "\tmeow" << std::endl;
}
