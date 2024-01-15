#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "-----Test consturctor-----" << std::endl;
	try
	{
		Bureaucrat tooLow("cat", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooHigh("cat", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----Test method-----" << std::endl;
	Bureaucrat low("cat", 150);
	try
	{
		low.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	low.incrementGrade();
	Bureaucrat high("cat", 1);
	try
	{
		high.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	high.decrementGrade();
	std::cout << "-----Test operator<<-----" << std::endl;
	std::cout << low << std::endl;
	return 0;
}