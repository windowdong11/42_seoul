#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

AForm *Intern::makePresidentialPardonForm(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

Intern::Intern()
{
}

Intern::Intern(const Intern& rhs)
{
	(void)rhs;
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string formName, std::string target) const
{
	FormCreateTable formCreateTable[3] = {
		{"PresidentialPardon", &Intern::makePresidentialPardonForm},
		{"RobotomyRequest", &Intern::makeRobotomyRequestForm},
		{"ShrubberyCreation", &Intern::makeShrubberyCreationForm}
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formCreateTable[i].formName)
			return (this->*formCreateTable[i].formMaker)(target);
	}
	std::cout << "Form " << formName << " not found" << std::endl;
	return NULL;
}
