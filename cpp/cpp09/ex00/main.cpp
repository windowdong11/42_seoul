#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstdlib>

#include <fstream>
#include <sstream>
#include <string>
#include <map>

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExchange exchange;
	if (!exchange.connectDatabase("data.csv"))
	{
		std::cout << "Error: could not open database file.\n";
		return 1;
	}
	std::ifstream input(argv[1]);
	if (input.fail())
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	std::string line;
	// ignore first line
	std::getline(input, line);
	while (std::getline(input, line))
	{
		// split line
		const char *const divider = " | ";
		const std::string::size_type divider_pos = line.find(divider);
		if (divider_pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}
		const std::string raw_date = line.substr(0, divider_pos);
		const std::string raw_count = line.substr(divider_pos + 3);
		double count;
		std::stringstream ss(raw_count);
		ss >> count;
		if (!ss.eof() || ss.fail())
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}
		if (!bitcoin_utils::isDateValid(raw_date))
		{
			std::cout << "Error: bad input => " << line << "\n";
			continue;
		}
		const BitcoinExchange::ExchangeResult result = exchange.buy(raw_date, std::atof(raw_count.c_str()));
		if (result.isSuccess())
		{
			std::cout << raw_date << " => " << count << " = " << result.getValue() << '\n';
		}
		else
		{
			std::cout << "Error: Failed to exchange => " << line << '\n';
		}
	}
	input.close();
	return 0;
}
