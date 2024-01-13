#include "Character.hpp"
#include <iostream>

Character::Character()
	: name("default")
{
	for (int i = 0; i < slotSize; i++)
		slot[i] = NULL;
}

Character::Character(const Character& rhs)
{
	for (int i = 0; i < slotSize; i++)
		slot[i] = NULL;
	operator=(rhs);
}

Character& Character::operator=(const Character& rhs)
{
	if (this == &rhs)
		return *this;
	name = rhs.name;
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

Character::~Character()
{
	for (int i = 0; i < slotSize; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
	}
}

Character::Character(std::string const &name)
	: name(name)
{
	for (int i = 0; i < slotSize; i++)
		slot[i] = NULL;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < slotSize; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			std::cout << "Equipped " << slot[i]->getType() << "at slot " << i << std::endl;
			return;
		}
	}
	std::cout << "No empty slot" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= slotSize)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (slot[idx] == NULL)
	{
		std::cout << "Empty slot" << std::endl;
		return;
	}
	std::cout << "Unequipped " << slot[idx]->getType() << std::endl;
	unequippedManager.add(slot[idx]);
	slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= slotSize)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (slot[idx] == NULL)
	{
		std::cout << "Empty slot" << std::endl;
		return;
	}
	slot[idx]->use(target);
}
