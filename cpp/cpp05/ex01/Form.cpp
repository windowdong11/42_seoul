#include "Form.hpp"

Form::Form()
	: name("default"), isSigned(false), gradeToSign(Bureaucrat::gradeLow), gradeToExecute(Bureaucrat::gradeLow)
{}

Form::Form(const Form& rhs)
	: name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{}

Form& Form::operator=(const Form& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Form::~Form()
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) throw(Form::GradeTooHighException, Form::GradeTooLowException)
{
}

bool Form::getIsSigned() const
{
	return false;
}

int Form::getGradeToSign() const
{
	return 0;
}
