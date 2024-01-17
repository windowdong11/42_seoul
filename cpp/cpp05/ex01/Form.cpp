#include "Form.hpp"

Form::Form()
	: name("Form"), isSigned(false), gradeToSign(Bureaucrat::gradeLow), gradeToExecute(Bureaucrat::gradeLow)
{}

Form::Form(const Form& rhs)
	: name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
	if (gradeToSign < Bureaucrat::gradeHigh || gradeToExecute < Bureaucrat::gradeHigh)
		throw Form::GradeTooHighException();
	if (gradeToSign > Bureaucrat::gradeLow || gradeToExecute > Bureaucrat::gradeLow)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Form::~Form()
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) throw(Form::GradeTooHighException, Form::GradeTooLowException)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < Bureaucrat::gradeHigh || gradeToExecute < Bureaucrat::gradeHigh)
		throw Form::GradeTooHighException();
	if (gradeToSign > Bureaucrat::gradeLow || gradeToExecute > Bureaucrat::gradeLow)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(Form::GradeTooLowException)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	os << rhs.getName() << " form, grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute() << ", signed: " << rhs.getIsSigned();
	return os;
}
