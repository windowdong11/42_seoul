#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
	: materiaCount(0)
{
	for (int i = 0; i < slotSize; i++)
		slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	for (int i = 0; i < slotSize; i++)
		slot[i] = NULL;
	operator=(rhs);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this == &rhs)
		return *this;
	materiaCount = rhs.materiaCount;
	for (int i = 0; i < slotSize; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
		if (rhs.slot[i] != NULL)
		{
			slot[i] = rhs.slot[i]->clone();
			*slot[i] = *rhs.slot[i];
		}
		else
			slot[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < slotSize; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (materiaCount < slotSize)
	{
		slot[materiaCount] = materia;
		materiaCount++;
	}
}

bool MateriaSource::isFull() const
{
	return materiaCount == slotSize;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < slotSize; i++)
	{
		if (slot[i] != NULL && slot[i]->getType() == type)
			return slot[i]->clone();
	}
	return NULL;
}
