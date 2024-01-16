#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	// Do not copy the sign status of the form
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
	/*
	Do not call this function.
	Copying a form to another existing form is not allowed.
	If you want to copy a form, use the copy constructor.
	*/
	AForm& operator=(const AForm& rhs);
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too low");
		}
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Form not signed");
		}
	};

	AForm();
	AForm(const AForm& rhs);
	virtual ~AForm();

	AForm(std::string name, int gradeToSign, int gradeToExecute) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat) throw(AForm::GradeTooLowException);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif