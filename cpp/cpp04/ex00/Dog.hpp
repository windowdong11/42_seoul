#ifndef DOG_HPP
#define DOG_HPP

#include "Cat.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound() const;
};

#endif