/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:50:44 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:48:24 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "color.hpp"

/*
** =============================================================================
** Contact
** =============================================================================
*/

std::string Contact::get_f_name(void) const
{
	return (_f_name);
}

std::string Contact::get_l_name(void) const
{
	return (_l_name);
}

std::string Contact::get_n_name(void) const
{
	return (_n_name);
}

std::string Contact::get_p_nbr(void) const
{
	return (_p_nbr);
}

std::string Contact::get_d_secret(void) const
{
	return (_d_secret);
}

/*
** =============================================================================
** PhoneBook
** =============================================================================
*/

void PhoneBook::prompt_header(void) const
{
	std::cout << std::endl
	<< std::setfill('=') << std::setw(49) << EOC << std::endl
	<< "|" << std::setfill(' ') << std::setw(44) << "My Awesome Phonebook |" << std::endl
	<< "|" << std::setfill(' ') << std::setw(44) << "by sshin |" << std::endl
	<< std::setfill('=') << std::setw(49) << EOC << std::endl;
}

PhoneBook::PhoneBook(void)
	: _flag_full(false), _idx(0)
{}

void PhoneBook::prompt_cmd(void) const
{
	std::cout << std::endl
	<< "Enter command to process [ " << RED << "EXIT" << EOC << " | "
	<< BYEL << "ADD" << EOC << " | "
	<< BLU << "SEARCH" << EOC << " ]" << std::endl
	<< ">> ";
}

void PhoneBook::get_cmd(void)
{
	const std::string white_spc_set = " \t\n\v\r\f";

	if ((std::getline(std::cin >> std::ws, _cmd)) == nullptr || std::cin.eof())
		exit(1);
	_cmd.erase(_cmd.find_last_not_of(white_spc_set) + 1);
}

int PhoneBook::convert_cmd(void) const
{
	if (_cmd == "EXIT")
		return (CMD_EXIT);
	else if (_cmd == "ADD")
		return (CMD_ADD);
	else if (_cmd == "SEARCH")
		return (CMD_SEARCH);
	return (ERR);
}

std::string PhoneBook::get_input(void) const
{
	return (_cmd);
}

void PhoneBook::process_add(void)
{
	std::string tmp;

	if (_flag_full)
	{
		std::cout << RED
		<< "The Phonebook is full, the Oldest contract will be OVERWRITTEN"
		<< EOC << std::endl;
	}
	std::cout << "Contact Index : [ "
	<< (_flag_full ? RED : BYEL) << _idx + 1 << EOC
	<< " / " << MAX_IDX << " ]" << std::endl << std::endl;
	_contact[_idx].set_field(INPUT_F_NAME, "1. First Name : ");
	_contact[_idx].set_field(INPUT_L_NAME, "2. Last Name : ");
	_contact[_idx].set_field(INPUT_N_NAME, "3. Nickname : ");
	_contact[_idx].set_field(INPUT_P_NBR, "4. Phone Number : ");
	_contact[_idx].set_field(INPUT_D_SECRET, "5. Darkest Secret : ");
	if (_flag_full == false && _idx == MAX_IDX - 1)
		_flag_full = true;
	_idx = (_idx + 1) % MAX_IDX;
}

void Contact::set_field(int input, const std::string &msg)
{
	std::string buf;
	const std::string white_spc_set = " \t\n\v\r\f";

	std::cout << msg;
	buf.clear();
	if (std::getline(std::cin >> std::ws, buf) == nullptr || std::cin.eof())
		exit(1);
	buf.erase(buf.find_last_not_of(white_spc_set) + 1);
	switch (input)
	{
		case INPUT_F_NAME:
			_f_name = buf;
			break ;
		case INPUT_L_NAME:
			_l_name = buf;
			break ;
		case INPUT_N_NAME:
			_n_name = buf;
			break ;
		case INPUT_P_NBR:
			_p_nbr = buf;
			break ;
		case INPUT_D_SECRET:
			_d_secret = buf;
			break ;
	}
}

void PhoneBook::process_search(void) const
{
	int size = (_flag_full ? MAX_IDX : _idx);

	if (size == 0)
	{
		std::cout << RED << "The Phonebook is empty" << EOC << std::endl;
		return ;
	}
	std::cout << std::setfill('=') << std::setw(49) << EOC << std::endl
	<< "|" << std::setfill(' ') << std::setw(MAX_WIDTH) << "index" << "|"
	<< std::setfill(' ') << std::setw(MAX_WIDTH) << "first name" << "|"
	<< std::setfill(' ') << std::setw(MAX_WIDTH) << "last name" << "|"
	<< std::setfill(' ') << std::setw(MAX_WIDTH) << "nickname" << "|" << std::endl
	<< std::setfill('=') << std::setw(49) << EOC << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "|" << BYEL << std::setfill(' ') << std::setw(MAX_WIDTH)
		<< i + 1 << EOC << "|"
		<< std::setfill(' ') << std::setw(MAX_WIDTH)
		<< _cut_str(_contact[i].get_f_name()) << "|"
		<< std::setfill(' ') << std::setw(MAX_WIDTH)
		<< _cut_str(_contact[i].get_l_name()) << "|"
		<< std::setfill(' ') << std::setw(MAX_WIDTH)
		<< _cut_str(_contact[i].get_n_name()) << "|" << std::endl
		<< std::setfill('=') << std::setw(49) << EOC << std::endl;
	}
	_print_res();
}

std::string PhoneBook::_cut_str(std::string str_to_cut) const
{
	if (str_to_cut.size() > MAX_WIDTH)
	{
		str_to_cut[MAX_WIDTH - 1] = '.';
		str_to_cut.erase(MAX_WIDTH);
	}
	return (str_to_cut);
}

void PhoneBook::_print_res(void) const
{
	int idx;

	while (1)
	{
		std::cout << std::endl << "Enter index to search (0 to close) >> ";
		std::cin >> idx;
		if (std::cin.fail() || idx < 0 || MAX_IDX < idx)
		{
			std::cout << RED << "Invalid input" << EOC << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		break ;
	}
	if (idx == 0)
		return ;
	std::cout << std::endl
	<< GRN << "1. First Name : " << EOC
	<< _contact[idx - 1].get_f_name() << std::endl
	<< GRN << "2. Last Name : " << EOC
	<<_contact[idx - 1].get_l_name() << std::endl
	<< GRN << "3. Nickname : " << EOC
	<< _contact[idx - 1].get_n_name() << std::endl
	<< GRN << "4. Phone Number : " << EOC
	<< _contact[idx - 1].get_p_nbr() << std::endl
	<< GRN << "5. Darkest Secret : " << EOC
	<< _contact[idx - 1].get_d_secret() << std::endl << std::endl;
}
