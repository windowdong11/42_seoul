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

	formCreateTable[0].formName = "PresidentialPardon";
	formCreateTable[0].formMaker = &Intern::makePresidentialPardonForm;
	formCreateTable[1].formName = "RobotomyRequest";
	formCreateTable[1].formMaker = &Intern::makeRobotomyRequestForm;
	formCreateTable[2].formName = "ShrubberyCreation";
	formCreateTable[2].formMaker = &Intern::makeShrubberyCreationForm;
}

Intern::Intern(const Intern& rhs)
	: formCreateTable(rhs.formCreateTable)
{}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 3; i++)
		formCreateTable[i] = rhs.formCreateTable[i];
	return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string formName, std::string target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == formCreateTable[i].formName)
			return (this->*formCreateTable[i].formMaker)(target);
	}
	std::cout << "Form " << formName << " not found" << std::endl;
	return NULL;
}
