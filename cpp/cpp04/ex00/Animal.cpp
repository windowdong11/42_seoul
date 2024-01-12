#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal()
	: type("Animal")
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "[Constructor] default" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "[Constructor] copy" << std::endl;
	*this = rhs;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "<op> =" << std::endl;
	if (this == &rhs)
		return *this;
	type = rhs.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << COLOR_BLUE << "Animal" << COLOR_RESET << "[Destructor]" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << COLOR_RED << "Animal" << COLOR_RESET << "[makeSound] Does not make any sound." << std::endl;
}

/*
가상 함수와 순수가상함수의 차이점

한줄 요약 : 가상함수에 정의가 없으면 순수가상함수가 된다.


*/