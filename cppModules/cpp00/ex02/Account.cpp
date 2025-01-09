#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

#define RED "\033[31m"
#define NOT "\033[0m"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << NOT;
	std::cout << ";amount:" << RED << _amount << NOT;
	std::cout << ";created" << std::endl;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << RED << getNbAccounts() << NOT;
	std::cout << ";total:" << RED << getTotalAmount() << NOT;
	std::cout << ";deposits:" << RED << getNbDeposits() << NOT;
	std::cout << ";withdrawals:" << RED << getNbWithdrawals() << NOT << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << NOT;
	std::cout << ";p_amount:" << RED << (checkAmount() - deposit) << NOT;
	std::cout << ";deposit:" << RED << deposit << NOT;
	std::cout << ";amount:" << RED << checkAmount() << NOT;
	std::cout << ";nb_deposits:" << RED << _nbDeposits << NOT << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	bool enough = checkAmount() >= withdrawal;
	if (enough) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << RED << _accountIndex << NOT;
		std::cout << ";p_amount:" << RED << (checkAmount() + withdrawal) << NOT;
		std::cout << ";withdrawal:" << RED << withdrawal << NOT;
		std::cout << ";amount:" << RED << checkAmount() << NOT;
		std::cout << ";nb_withdrawals:" << RED << _nbWithdrawals << NOT << std::endl;
		return (true);
	}	
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << NOT;
	std::cout << ";p_amount:" << RED << checkAmount() << NOT;
	std::cout << ";withdrawal:refused" << NOT << std::endl;
	return (false);
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << NOT;
	std::cout << ";amount:" << RED << _amount << NOT;
	std::cout << ";deposits:" << RED << _nbDeposits << NOT;
	std::cout << ";withdrawals:" << RED << _nbWithdrawals << NOT << std::endl; 
}

Account::~Account( void ) {
	_totalAmount -= checkAmount();
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << NOT;
	std::cout << ";amount:" << RED << checkAmount() << NOT << ";closed" << std::endl;	
}

// Estáticas
int		Account::getNbAccounts(void) {
	return _nbAccounts;
}

int		Account::getTotalAmount(void) {
	return _totalAmount;
}

int		Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm *localTime = std::localtime(&now);

	std::cout << "[";
	std::cout << (1900 + localTime->tm_year);
	std::cout << (localTime->tm_mon + 1 < 10 ? "0" : "") << (localTime->tm_mon + 1);
	std::cout << (localTime->tm_mday < 10 ? "0" : "") << localTime->tm_mday;
	std::cout << "_";
    std::cout << (localTime->tm_hour < 10 ? "0" : "") << localTime->tm_hour;
    std::cout << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min;
	std::cout << (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec;
	std::cout << "] ";
}