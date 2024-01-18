#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
private:
	AForm* makePresidentialPardonForm(std::string target) const;
	AForm* makeRobotomyRequestForm(std::string target) const;
	AForm* makeShrubberyCreationForm(std::string target) const;
	struct FormCreateTable {
		std::string formName;
		AForm* (Intern::*formMaker)(std::string target) const;
	};
public:
	Intern();
	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);
	~Intern();

	AForm* makeForm(std::string formName, std::string target) const;
};

#endif