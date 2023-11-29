#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "need three parameters : filename <needle> <haystack>" << std::endl;
		return 1;
	}
	const std::string filename(argv[1]);
	const std::string outfilename(filename + ".replace");
	const std::string needle(argv[2]);
	const std::string haystack(argv[3]);
	if (needle.length() == 0)
	{
		std::cout << "needle cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str(), std::ifstream::in);
	if (!infile.good())
	{
		std::cout << "failed to open file : " << filename << std::endl;
		return 1;
	}

	std::ofstream outfile(outfilename.c_str(), std::ofstream::out);
	if (!outfile.good())
	{
		infile.close();
		std::cout << "failed to open file : " << outfilename << std::endl;
		return 1;
	}

	const size_t keyword_len = needle.length();
	std::string line;
	while (std::getline(infile, line))
	{
		std::string newline;
		size_t from = 0;
		size_t next;
		while (true)
		{
			next = line.find(needle, from);
			if (line.npos == next)
			{
				newline.append(line.begin() + from, line.end());
				break;
			}
			newline.append(line.begin() + from, line.begin() + next);
			newline.append(haystack);
			from = next + keyword_len;
		}
		outfile << newline << std::endl;
		if (!outfile.good())
		{
			std::cout << "failed to write to file : " << outfilename << std::endl;
			infile.close();
			return 1;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}