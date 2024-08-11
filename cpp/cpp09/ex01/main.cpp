#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"[expression]\"" << std::endl;
		return 1;
	}
	Result<int> result = RPN::calculate(argv[1]);
	if (result.isSuccess())
		std::cout << result.getValue() << std::endl;
	else
		std::cout << "Error" << std::endl;
	return 0;
}