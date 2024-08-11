#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	(void)rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void)rhs;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::connectDatabase(const std::string &filename)
{
	std::ifstream dbfile(filename.c_str());
	if (dbfile.fail())
	{
		std::cout << "Error: could not open database file.\n";
		return 1;
	}
	bool result = true;
	std::string line;
	// ignore first line
	std::getline(dbfile, line);
	while (std::getline(dbfile, line))
	{
		const char *const divider = ",";
		const std::string::size_type divider_pos = line.find(divider);
		const std::string raw_date = line.substr(0, divider_pos);
		if (bitcoin_utils::isDateValid(raw_date) == false)
		{
			result = false;
			break;
		}
		const std::string raw_exchange_rate = line.substr(divider_pos + 1);
		std::stringstream ss(raw_exchange_rate);
		t_rate exchange_rate;
		ss >> exchange_rate;
		if (!ss.eof() || ss.fail())
		{
			result = false;
			break;
		}
		db[raw_date] = exchange_rate;
	}
	dbfile.close();
	return result;
}

BitcoinExchange::ExchangeResult BitcoinExchange::buy(const std::string &date, t_value value) const
{
	if (value < 0.0)
	{
		std::cout << "Error: not a positive number.\n";
		return ExchangeResult(ExchangeResult::FAIL, 0.0);
	}
	else if (value > 1000.0)
	{
		std::cout << "Error: too large a number.\n";
		return ExchangeResult(ExchangeResult::FAIL, 0.0);
	}
	t_DB::const_iterator bitcoin_value = db.lower_bound(date);
	if (bitcoin_value == db.end())
		return ExchangeResult(ExchangeResult::FAIL, 0.0);
	// std::cout << "get value at : " << bitcoin_value->first << "," << bitcoin_value->second << "\n";
	return ExchangeResult(ExchangeResult::SUCCESS, bitcoin_value->second * value);
}
