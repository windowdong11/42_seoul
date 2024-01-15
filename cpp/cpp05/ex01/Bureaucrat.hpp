#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* include headers */
#include <string>
#include <ostream>

class Bureaucrat
{
private:
	std::string name;
	int grade;

public:
	static const int gradeHigh = 1;
	static const int gradeLow = 150;
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
	
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat &operator=(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
	std::string getName() const;
	int getGrade() const;

	void incrementGrade() throw(Bureaucrat::GradeTooHighException);
	void decrementGrade() throw(Bureaucrat::GradeTooLowException);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
