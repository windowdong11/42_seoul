#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int slotSize = 4;
	AMateria *slot[4];
	int materiaCount;
public:
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	/*
	This function does not handle the pointer when it is full.
	Check is full by calling isFull() function.
	*/
	void learnMateria(AMateria *);
	bool isFull() const;
	AMateria *createMateria(std::string const &type);
};

#endif