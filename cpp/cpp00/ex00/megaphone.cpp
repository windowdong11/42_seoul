#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		std::string s("");
		for (int i = 1; i < argc; ++i)
			s += argv[i];
		for (std::string::iterator it = s.begin(); it != s.end(); ++it)
			*it = std::toupper(*it);
		std::cout << s << std::endl;
	}
	return (0);
}
