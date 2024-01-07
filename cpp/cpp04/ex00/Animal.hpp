#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);
	~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif