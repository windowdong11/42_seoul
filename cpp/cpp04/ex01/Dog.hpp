#ifndef DOG_HPP
#define DOG_HPP

#include "Cat.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound() const;
};

#endif