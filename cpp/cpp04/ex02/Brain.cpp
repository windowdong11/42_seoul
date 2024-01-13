#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

Brain::Brain()
{
	if (DEBUG_BRAIN)
		std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& rhs)
{
	if (DEBUG_BRAIN)
		std::cout << "Brain copy constructor called" << std::endl;
	*this = rhs;
}

Brain& Brain::operator=(const Brain& rhs)
{
	(void)rhs;
	std::cout << "Brain operator= called" << std::endl;
	if (this == &rhs)
	{
		std::cout << "not copied (same object)" << std::endl;
		return *this;
	}
	std::cout << "\tcopy" << std::endl;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = rhs.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	if (DEBUG_BRAIN)
		std::cout << "Brain destructor called" << std::endl;
}
