#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* include headers */
#include <string>

class Bureaucrat
{
private:
	std::string name;
	int grade;
	static const int gradeHigh = 1;
	static const int gradeLow = 150;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat &operator=(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
};

#endif
