#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
	// Tests for all the forms
	{
		std::cout << COLOR_CYAN << "----- Test operator<<()" << COLOR_RESET << std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		std::cout << shrubbery << std::endl;
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		RobotomyRequestForm robotomy("robot");
		std::cout << robotomy << std::endl;
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		PresidentialPardonForm presidential("president");
		std::cout << presidential << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test execute() for signed form (grade: 150)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		Bureaucrat master("master", 1);
		shrubbery.beSigned(master);
		robotomy.beSigned(master);
		presidential.beSigned(master);
		Bureaucrat slave("intern", 150);
		std::cout << slave << std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		try {
			shrubbery.execute(slave);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		
		}
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		try {
			robotomy.execute(slave);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		}
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		try {
			presidential.execute(slave);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test execute() for signed form (grade: 1)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		Bureaucrat master("master", 1);
		shrubbery.beSigned(master);
		robotomy.beSigned(master);
		presidential.beSigned(master);
		std::cout << master	<< std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		shrubbery.execute(master);
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		robotomy.execute(master);
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		presidential.execute(master);
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test execute() for unsigned form (grade: 150)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		// Bureaucrat master("master", 1);
		// shrubbery.beSigned(master);
		// robotomy.beSigned(master);
		// presidential.beSigned(master);
		Bureaucrat slave("intern", 150);
		std::cout << slave << std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		try {
			shrubbery.execute(slave);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		
		}
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		try {
			robotomy.execute(slave);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		}
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		try {
			presidential.execute(slave);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test execute() for unsigned form (grade: 1)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		Bureaucrat master("master", 1);
		// shrubbery.beSigned(master);
		// robotomy.beSigned(master);
		// presidential.beSigned(master);
		std::cout << master	<< std::endl;
		try {
			shrubbery.execute(master);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		
		}
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		try {
			robotomy.execute(master);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		}
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		try {
			presidential.execute(master);
		} catch (std::exception& e) {
			std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test executeForm() for signed form (grade: 150)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		Bureaucrat master("master", 1);
		shrubbery.beSigned(master);
		robotomy.beSigned(master);
		presidential.beSigned(master);
		Bureaucrat slave("intern", 150);
		std::cout << slave << std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		slave.executeForm(shrubbery);
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		slave.executeForm(robotomy);
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		slave.executeForm(presidential);
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test executeForm() for signed form (grade: 1)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		Bureaucrat master("master", 1);
		shrubbery.beSigned(master);
		robotomy.beSigned(master);
		presidential.beSigned(master);
		std::cout << master	<< std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		master.executeForm(shrubbery);
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		master.executeForm(robotomy);
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		master.executeForm(presidential);
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test executeForm() for unsigned form (grade: 150)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		// Bureaucrat master("master", 1);
		// shrubbery.beSigned(master);
		// robotomy.beSigned(master);
		// presidential.beSigned(master);
		Bureaucrat slave("intern", 150);
		std::cout << slave << std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		slave.executeForm(shrubbery);
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		slave.executeForm(robotomy);
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		slave.executeForm(presidential);
	}
	std::cout << std::endl;

	{
		std::cout << COLOR_CYAN << "----- Test executeForm() for unsigned form (grade: 1)" << COLOR_RESET << std::endl;
		ShrubberyCreationForm shrubbery("shrub");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");
		Bureaucrat master("master", 1);
		// shrubbery.beSigned(master);
		// robotomy.beSigned(master);
		// presidential.beSigned(master);
		std::cout << master	<< std::endl;
		std::cout << COLOR_YELLOW << "ShrubberyCreationForm" << COLOR_RESET << std::endl;
		std::cout << shrubbery << std::endl;
		master.executeForm(shrubbery);
		std::cout << COLOR_YELLOW << "RobotomyRequestForm" << COLOR_RESET << std::endl;
		std::cout << robotomy << std::endl;
		master.executeForm(robotomy);
		std::cout << COLOR_YELLOW << "PresidentialPardonForm" << COLOR_RESET << std::endl;
		std::cout << presidential << std::endl;
		master.executeForm(presidential);
	}
	std::cout << std::endl;
	return 0;
}