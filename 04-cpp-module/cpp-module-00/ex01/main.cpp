/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:26:39 by sshin             #+#    #+#             */
/*   Updated: 2022/02/15 16:03:57 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;

	pb.prompt_header();
	while (1)
	{
		pb.prompt_cmd();
		pb.get_cmd();
		switch (pb.convert_cmd())
		{
			case CMD_EXIT :
				return (0);
			case CMD_ADD :
				std::cout << "Adding a new contact to the Phonebook..." << std::endl;
				pb.process_add();
				break ;
			case CMD_SEARCH :
				std::cout << "Searching the contact from the Phonebook..." << std::endl;
				pb.process_search();
				break ;
			default :
				std::cout << "Invalid input : " << pb.get_input() << std::endl;
				break ;
		}
	}
	return (0);
}
