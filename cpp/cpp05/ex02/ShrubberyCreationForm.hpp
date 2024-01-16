#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/* include */
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;

public:
	class FileOpenException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("File open error");
		}
	};
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	void execute(Bureaucrat const &executor) const;

private:
	/*
	Do not call this function.
	Copying a form to another existing form is not allowed.
	If you want to copy a form, use the copy constructor.
	*/
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};

#endif