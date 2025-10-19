/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:57:24 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:55:15 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen k;

	if (argc != 2)
		std::cout << "Invalid arguments" << std::endl
		<< "Usage: ./karenFilter [Level]" << std::endl;
	else
		k.complain(argv[1]);
	return (0);
}
