#include "utils.hpp"
#include <iostream>
#include <sstream>

namespace bitcoin_utils
{
	bool isDateValid(const std::string &raw_date)
	{
		std::stringstream ss(raw_date);
		int year, month, day;
		char delim1, delim2;
		ss >> year >> delim1 >> month >> delim2 >> day;
		if (delim1 != '-' || delim2 != '-')
			return false;
		if (!ss.eof() || ss.fail())
			return false;
		const int last_days[] = {
				31, 29, 31, 30, 31, 30,
				31, 31, 30, 31, 30, 31};
		if (year < 0 || month < 1 || 12 < month || day < 1 || last_days[month - 1] < day)
			return false;
		if (month == 2 && day == 29)
		{
			if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
				return false;
		}
		return true;
	}
}