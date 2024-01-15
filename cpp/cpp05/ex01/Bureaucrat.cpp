#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("default"), grade(gradeLow)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		name = other.name;
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
	: name(name), grade(grade)
{
	if (grade < gradeHigh)
		throw Bureaucrat::GradeTooHighException();
	if (grade > gradeLow)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade() throw(Bureaucrat::GradeTooHighException)
{
	if (grade == gradeHigh)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() throw(Bureaucrat::GradeTooLowException)
{
	if (grade == gradeLow)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
