/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:33 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:17:33 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int i[5] = {1, 2, 3, 4, 5};
	double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string s[3] = {"Hi", "42", "Seoul"};

	std::cout << "Int Iteration\t\t: ";
	iter(i, sizeof(i) / sizeof(*i), print);
	std::cout << std::endl;

	std::cout << "Double Iteration\t: ";
	iter(d, sizeof(d) / sizeof(*d), print);
	std::cout << std::endl;

	std::cout << "Char Iteration\t\t: ";
	iter(c, sizeof(c) / sizeof(*c), print);
	std::cout << std::endl;

	std::cout << "String Iteration\t: ";
	iter(s, sizeof(s) / sizeof(*s), print);
	std::cout << std::endl;
	return (0);
}
