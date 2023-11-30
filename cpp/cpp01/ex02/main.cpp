#include <string>
#include <iostream>

int main()
{
	std::string variable("HI THIS IS BRAIN");
	std::string* stringPTR = &variable;
	std::string& stringREF = variable;

	std::cout << "The memory address of the string variable : " << &variable << std::endl;
	std::cout << "The memory address held by stringPTR." <<  &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF." << &stringREF << std::endl;

	std::cout << "The value of the string variable." << variable << std::endl;
	std::cout << "The value pointed to by stringPTR." << stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF" << stringREF << std::endl;
	return 0;
}