#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl na;

	std::cout << "[DEBUG]" << std::endl;
	na.complain("DEBUG");
	std::cout << "[INFO]" << std::endl;
	na.complain("INFO");
	std::cout << "[WARNING]" << std::endl;
	na.complain("WARNING");
	std::cout << "[ERROR]" << std::endl;
	na.complain("ERROR");
	std::cout << "[PLAY]" << std::endl;
	na.complain("PLAY");
}