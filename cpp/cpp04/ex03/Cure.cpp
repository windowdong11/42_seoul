#include "Cure.hpp"
#include <iostream>

Cure::Cure()
	: AMateria()
{
	materiaType = "cure";
}

Cure::Cure(const Cure& rhs)
	: AMateria(rhs)
{
	materiaType = rhs.getType();
}

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
