/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:56:42 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:51:28 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static std::ostream &_print_idx_and_amount(int idx, int amount, bool flag_prv)
{
	return (std::cout << "index:" << idx
			<< (flag_prv ? ";p_amount:" : ";amount:") << amount);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t ltime;
	struct tm *cur_time;

	ltime = time(&ltime);
	cur_time = localtime(&ltime);
	std::cout << "[" << cur_time->tm_year + 1900
	<< std::setfill('0') << std::setw(2) << cur_time->tm_mon
	<< std::setfill('0') << std::setw(2) << cur_time->tm_mday << "_"
	<< std::setfill('0') << std::setw(2) << cur_time->tm_hour
	<< std::setfill('0') << std::setw(2) << cur_time->tm_min
	<< std::setfill('0') << std::setw(2) << cur_time->tm_sec << "] ";
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	_print_idx_and_amount(_accountIndex, _amount, false)
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	_print_idx_and_amount(_accountIndex, _amount, true)
	<< ";deposit:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << ++_nbDeposits << std::endl;
	_amount += deposit;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	_print_idx_and_amount(_accountIndex, _amount, true);
	if (_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	return (true);
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	_print_idx_and_amount(_accountIndex, _amount, false) << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	_print_idx_and_amount(_accountIndex, _amount, false) << ";closed" << std::endl;
}
