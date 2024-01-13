#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal()
	: type("Animal")
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "[Constructor] default" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "[Constructor] copy" << std::endl;

	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "<op> =" << std::endl;
	if (this == &rhs)
	{
		std::cout << "\tnot copied (same object)" << std::endl;

		return *this;
	}
	std::cout << "\tcopy" << std::endl;
	type = rhs.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "[Destructor]" << std::endl;
}

std::string Animal::getType() const
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "{getType}" << std::endl;
	return type;
}

// void Animal::makeSound() const
// {
// 	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "{makeSound}" << std::endl;
// 	std::cout << "\tDoes not make any sound." << std::endl;
// }