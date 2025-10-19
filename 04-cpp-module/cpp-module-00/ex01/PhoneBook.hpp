/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:50:42 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:48:28 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CPP
# define PHONE_BOOK_CPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>

# define MAX_IDX 8
# define MAX_WIDTH 10
# define ERR -1

enum Cmd
{
	CMD_EXIT,
	CMD_ADD,
	CMD_SEARCH
};

enum Input
{
	INPUT_F_NAME,
	INPUT_L_NAME,
	INPUT_N_NAME,
	INPUT_P_NBR,
	INPUT_D_SECRET
};

class Contact
{
private :
	std::string _f_name;
	std::string _l_name;
	std::string _n_name;
	std::string _p_nbr;
	std::string _d_secret;

public :
	void set_field(int f_type, const std::string &msg);
	std::string get_f_name(void) const;
	std::string get_l_name(void) const;
	std::string get_n_name(void) const;
	std::string get_p_nbr(void) const;
	std::string get_d_secret(void) const;
};

class PhoneBook
{
private :
	std::string _cmd;
	bool _flag_full;
	int _idx;
	Contact _contact[MAX_IDX];

	std::string _cut_str(std::string s) const;
	void _print_res(void) const;

public :
	void prompt_header(void) const;
	void prompt_cmd(void) const;
	void get_cmd(void);
	int convert_cmd(void) const;
	void process_add(void);
	void process_search(void) const;
	std::string get_input(void) const;

	PhoneBook(void);
};

#endif
