#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/* include */
#include "Result.tpp"
#include <string>
#include <map>

class BitcoinExchange
{
private:
	typedef double t_value;
	typedef double t_rate;
	typedef std::map<std::string, t_rate, std::greater<std::string> > t_DB;

public:
	typedef Result<t_value> ExchangeResult;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	bool connectDatabase(const std::string &filename);
	ExchangeResult buy(const std::string &date, t_value value) const;

private:
	t_DB db;
};

#endif