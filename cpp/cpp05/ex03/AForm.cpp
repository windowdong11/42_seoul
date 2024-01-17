#include "AForm.hpp"

AForm::AForm()
	: name("default"), isSigned(false), gradeToSign(Bureaucrat::gradeLow), gradeToExecute(Bureaucrat::gradeLow)
{}

AForm::AForm(const AForm& rhs)
	: name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
	if (gradeToSign < Bureaucrat::gradeHigh || gradeToExecute < Bureaucrat::gradeHigh)
		throw AForm::GradeTooHighException();
	if (gradeToSign > Bureaucrat::gradeLow || gradeToExecute > Bureaucrat::gradeLow)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

AForm::~AForm()
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < Bureaucrat::gradeHigh || gradeToExecute < Bureaucrat::gradeHigh)
		throw AForm::GradeTooHighException();
	if (gradeToSign > Bureaucrat::gradeLow || gradeToExecute > Bureaucrat::gradeLow)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) throw(AForm::GradeTooLowException)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	os << rhs.getName() << " form, grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute() << ", signed: " << rhs.getIsSigned();
	return os;
}
