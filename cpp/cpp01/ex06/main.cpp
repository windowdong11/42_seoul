#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "usage: ./harlFilter <complain>" << std::endl;
		return 1;
	}
	Harl na;

	na.complain(argv[1]);
	return 0;
}