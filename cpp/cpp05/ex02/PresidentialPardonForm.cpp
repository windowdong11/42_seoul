#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
	: AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute()), target(rhs.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this == &rhs)
		return (*this);
	target = rhs.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
