#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(const AMateria& rhs)
	: materiaType(rhs.getType())
{}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

AMateria::~AMateria()
{}

AMateria::AMateria(std::string const &type)
	: materiaType(type)
{
}

std::string const &AMateria::getType() const
{
	return materiaType;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
