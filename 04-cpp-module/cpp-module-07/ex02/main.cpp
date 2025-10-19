/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:17:27 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:17:28 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << "========== Int Test ==========" << std::endl;
	test<int>(10);
	std::cout << std::endl;

	std::cout << "========== Double Test ==========" << std::endl;
	test<double>(10);
	std::cout << std::endl;

	std::cout << "========== Char Test ==========" << std::endl;
	test<char>(10);
	std::cout << std::endl;

	std::cout << "========== Const Test ==========" << std::endl;
	const Array<char> c(10);
	for (std::size_t i = 0 ; i < 10; ++i)
	{
		*(const_cast<char*>(&c[i])) = static_cast<char>(i + '0');
		std::cout << c[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "========== Copy Test ==========" << std::endl;
	Array<std::string> arr1(3);
	arr1[0] = "Hi";
	arr1[1] = "42";
	arr1[2] = "Seoul";
	Array<std::string> arr2(arr1);
	for (std::size_t i = 0 ; i < arr1.size() ; ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	for (std::size_t i = 0 ; i < arr1.size() ; ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	return (0);
}

/*
** Preventive Allocation
** https://42born2code.slack.com/archives/CN9RHKQHW/p1640731442373400
*/
