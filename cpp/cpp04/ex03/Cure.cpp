#include "Cure.hpp"
#include <iostream>

Cure::Cure()
	: AMateria("cure")
{}

Cure::Cure(const Cure& rhs)
	: AMateria(rhs)
{}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this == &rhs)
		return *this;
	AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure()
{}

Cure *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
