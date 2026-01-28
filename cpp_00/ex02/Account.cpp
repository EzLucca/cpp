#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {return _nbAccounts ;}
int	Account::getTotalAmount( void ){return _totalAmount ;};
int	Account::getNbDeposits( void ){return _totalNbDeposits;};
int	Account::getNbWithdrawals( void ){return _totalNbWithdrawals;};

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created\n";
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << "\n";
};

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";"
		<< "p_amount:" << _amount << ";"
		<< "deposits:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:"<< _amount<< ";" 
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";"
			<< "withdrawal: refused\n";
		return(false);
	}
	std::cout << "index:" << _accountIndex<< ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:"<< _amount<< ";" 
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	_displayTimestamp();
	return(_totalAmount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
}

void	Account::_displayTimestamp(void)
{
	char	output[17];
	time_t	timeCheck = std::time(NULL);
	std::strftime(output, 17, "%Y%m%d_%H%M%S", std::localtime(&timeCheck));
	std::cout << "[" << output << "] ";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";ammount:" << _amount << ";closed\n";
}
