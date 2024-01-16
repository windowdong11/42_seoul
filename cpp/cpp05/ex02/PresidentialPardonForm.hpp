#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/* include */
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	void execute(Bureaucrat const &executor) const;

private:
	/*
	Do not call this function.
	Copying a form to another existing form is not allowed.
	If you want to copy a form, use the copy constructor.
	*/
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
};

#endif