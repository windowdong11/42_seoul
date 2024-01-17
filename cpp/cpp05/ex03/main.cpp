#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define COLOR_RESET "\033[0m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLUE "\033[34m"

int main()
{
	std::srand(std::time(NULL));
	{
		std::cout << COLOR_CYAN << "----- Test create forms" << COLOR_RESET << std::endl;
		Bureaucrat master("Master", 1);
		Intern intern;

		std::cout << std::endl;
		std::cout << COLOR_YELLOW << "----- Test ShrubberyCreationForm" << COLOR_RESET << std::endl;
		AForm* shurb = intern.makeForm("ShrubberyCreation", "home");
		std::cout << *shurb << std::endl;
		shurb->beSigned(master);
		shurb->execute(master);
		std::cout << *shurb << std::endl;

		std::cout << std::endl;
		std::cout << COLOR_YELLOW << "----- Test RobotomyRequestForm" << COLOR_RESET << std::endl;
		AForm* robot = intern.makeForm("RobotomyRequest", "Nikita");
		std::cout << *robot << std::endl;
		robot->beSigned(master);
		robot->execute(master);
		std::cout << *robot << std::endl;

		std::cout << std::endl;
		std::cout << COLOR_YELLOW << "----- Test PresidentialPardonForm" << COLOR_RESET << std::endl;
		AForm* presi = intern.makeForm("PresidentialPardon", "Leela");
		std::cout << *presi << std::endl;
		presi->beSigned(master);
		presi->execute(master);
		std::cout << *presi << std::endl;
		delete shurb;
		delete robot;
		delete presi;
	}
	return 0;
}