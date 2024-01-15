#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form
{
private:
	const std::string name;
	// Do not copy the sign status of the form
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
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

	Form();
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();

	Form(std::string name, int gradeToSign, int gradeToExecute) throw(Form::GradeTooHighException, Form::GradeTooLowException);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat) throw(Form::GradeTooLowException);
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif