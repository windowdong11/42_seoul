#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: name("Bureaucrat"), grade(gradeLow)
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

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << name << " cannot sign " << form.getName() << " because " << e.what() << "." << std::endl;
		return;
	}
	std::cout << name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[31m" << name << " failed to execute " << form.getName() << std::endl
					<< "reason : " << e.what() << "\033[0m" << std::endl;
		return;
	}
	std::cout << name << " executed " << form.getName() << std::endl;
}
