#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "need three parameters : filename <string1> <string2>" << std::endl;
		return 1;
	}
	std::ifstream infile(argv[1], std::ifstream::in);
	if (!infile.good())
	{
		std::cout << "failed to open file : " << argv[1] << std::endl;
		return 1;
	}
	return 0;
}