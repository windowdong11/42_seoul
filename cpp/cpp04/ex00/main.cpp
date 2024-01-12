#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal *animal = new Animal();
	std::cout << std::endl;

	const Animal *dog = new Dog();
	std::cout << std::endl;

	const Animal *cat = new Cat();
	std::cout << std::endl;


	std::cout << ">> Test getType()" << std::endl;
	std::cout << "animal : " << animal->getType() << std::endl;
	std::cout << "dog : " << dog->getType() << std::endl;
	std::cout << "cat : " << cat->getType() << std::endl;
	std::cout << std::endl;

	std::cout << ">> Test makeSound()" << std::endl;
	std::cout << "animal : ";
	animal->makeSound();
	std::cout << "cat : ";
	cat->makeSound(); // will output the cat sound!
	std::cout << "dog : ";
	dog->makeSound();
	std::cout << std::endl;

	delete cat;
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;

	delete animal;
	return (0);
}