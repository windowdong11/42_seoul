#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
			<< "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

Account::Account(int initial_deposit)
		: _accountIndex(getNbAccounts()),
			_amount(initial_deposit),
			_nbDeposits(0),
			_nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "created"
			<< std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "closed"
			<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	const int p_amount = _amount;

	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;

	// print deposit information
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << _amount << ";"
			<< "nb_deposits:" << _nbDeposits
			<< std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	const int p_amount = _amount;
	if (_amount > withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		_displayTimestamp();
		std::cout
				<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	}
	else
	{
		_displayTimestamp();
		std::cout
				<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "withdrawal:refused"
				<< std::endl;
	}
	return true;
}
int Account::checkAmount(void) const
{
	return _amount;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals
			<< std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t rawtime;
	std::time(&rawtime);

	char buffer[32];
	std::strftime(buffer, 32, "[%Y%m%d_%H%M%S] ", localtime(&rawtime));
	std::cout << buffer;
}

// int				_accountIndex;
// int				_amount;
// int				_nbDeposits;
// int				_nbWithdrawals;

Account::Account(void) {}