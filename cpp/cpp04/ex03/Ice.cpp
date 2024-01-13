#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	materiaType = "ice";
}

Ice::Ice(const Ice& rhs)
{
	materiaType = rhs.getType();
}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this == &rhs)
		return *this;
	AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice()
{}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
