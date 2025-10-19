/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:55:06 by sshin             #+#    #+#             */
/*   Updated: 2022/02/15 20:42:26 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	const std::string str = std::string("HI THIS IS BRAIN");
	const std::string *stringPTR = &str;
	const std::string &stringREF = str;

	std::cout << "Address of str: " << &str << std::endl
	<< "Address of stringPTR: " << stringPTR << std::endl
	<< "Address of stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Display by str: " << str << std::endl
	<< "Display by stringPTR: " << *stringPTR << std::endl
	<< "Display by stringREF: " << stringREF << std::endl;
	return (0);
}
