#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main()
{
	const Animal *dog = new Dog();
	std::cout << std::endl;

	const Animal *cat = new Cat();
	std::cout << std::endl;
	

	delete cat;
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;

	Animal *animals[10];

	std::cout << ">> Test default constructor (create dogs)" << std::endl;
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	std::cout << std::endl;

	std::cout << ">> Test default constructor (create cats)" << std::endl;
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	std::cout << std::endl;

	std::cout << ">> Test desturctor" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << std::endl;
	
	std::cout << ">> Test deep copy" << std::endl;
	Cat originalCat;
	Cat copyCat(originalCat);
	return (0);
}