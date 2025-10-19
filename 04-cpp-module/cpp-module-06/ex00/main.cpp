/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:28:29 by sshin             #+#    #+#             */
/*   Updated: 2022/02/20 19:26:16 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Invalid input" << std::endl
			<< "Usage: ./convert [Argument to convert]" << std::endl;
	else
		std::cout << Convert(argv[1]);
	return (0);
}

/*
** char: 'c'(99), 'a'(97)
** int: 0, -42, 42
** float: 0.0f, -4.2f, 4.2f, -inff, +inff and nanf
** double: 0.0, -4.2, 4.2, -inf, +inf and nan
*/
