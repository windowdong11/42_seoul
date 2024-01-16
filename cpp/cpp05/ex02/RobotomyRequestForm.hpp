#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

/* include */
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	void execute(Bureaucrat const &executor) const;

private:
	/*
	Do not call this function.
	Copying a form to another existing form is not allowed.
	If you want to copy a form, use the copy constructor.
	*/
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
};

#endif