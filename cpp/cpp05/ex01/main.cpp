#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLUE "\033[34m"

int main()
{
	std::cout << std::endl << "-----Test getter-----" << std::endl;
	Form form(std::string(COLOR_YELLOW) + "Form_50/10" + COLOR_RESET, 50, 10);
	std::cout << "name : " << form.getName() << std::endl;
	std::cout << "gradeToSign : " << form.getGradeToSign() << std::endl;
	std::cout << "gradeToExecute : " << form.getGradeToExecute() << std::endl;
	std::cout << "isSigned : " << form.getIsSigned() << std::endl;
	std::cout << form << std::endl;
	std::cout << std::endl << "-----Test beSigned-----" << std::endl;
	Bureaucrat low(std::string(COLOR_GREEN) + "bur_70" + COLOR_RESET, 70);
	std::cout << low << std::endl;
	try {
		form.beSigned(low);
		std::cout << "successfully signed in try-catch" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << form << std::endl;
	Bureaucrat high("bureaucrat", 30);
	std::cout << high << std::endl;
	try {
		form.beSigned(high);
		std::cout << "successfully signed in try-catch" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << form << std::endl;
	std::cout << std::endl << "-----Test signForm-----" << std::endl;
	low.signForm(form);
	high.signForm(form);
	std::cout << std::endl << "-----Test consturctor-----" << std::endl;
	try
	{
		Form tryForm("form", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tryForm("form", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tryForm("form", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form tryForm("form", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}