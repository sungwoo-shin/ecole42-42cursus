/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:24:43 by sshin             #+#    #+#             */
/*   Updated: 2022/03/06 17:07:31 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	std::cout << "========== default test ==========" << std::endl;
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(5);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "========== exception test ==========" << std::endl;
	Span sp2 = Span(3);
	try // empty test
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try // emtpy test
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try // full test
	{
		sp2.addNumber(1);
		std::cout << "addNumber success!" << std::endl;
		sp2.addNumber(2);
		std::cout << "addNumber success!" << std::endl;
		sp2.addNumber(3);
		std::cout << "addNumber success!" << std::endl;
		sp2.addNumber(4);
		std::cout << "addNumber success!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "========== iterator test ==========" << std::endl;
	Span sp3 = Span(10001);
	std::vector<int> vec;
	for (int i = 10000; i > 0; --i)
		vec.push_back(i);
	sp3.addNumber(vec.begin(), vec.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
}
