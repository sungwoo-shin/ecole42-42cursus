/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:34:27 by sshin             #+#    #+#             */
/*   Updated: 2022/03/06 16:23:11 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;

	for (int i = 0; i < 10; ++i)
		vec.push_back(i);
	std::vector<int>::iterator iter = begin(vec);
	std::cout << "vec : ";
	while (iter != end(vec))
		std::cout << *iter++ << " ";
	std::cout << std::endl;

	try
	{
		int ret = easyfind(vec, 5);
		std::cout << "Success : " << ret << std::endl;
		ret = easyfind(vec, 11);
		std::cout << "Success : " << ret << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Fail : " << e.what() << std::endl;
	}
	return (0);
}
