/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:20:48 by sshin             #+#    #+#             */
/*   Updated: 2022/03/06 18:22:57 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "mutantstack.hpp"
#include "mutantstack.cpp"

template <typename Iter>
void print(Iter begin, Iter end)
{
	std::cout << "(Bottom) ";
	while (begin != end)
	{
		std::cout << *begin << ' ';
		++begin;
	}
	std::cout << "(Top)" << std::endl;
}

int main(void)
{
	MutantStack<int> mstack;

	std::cout << "========== defatult test ==========" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	print(mstack.begin(), mstack.end());

	std::cout << "========== defatult test ==========" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(100);
	print(mstack.begin(), mstack.end());

	std::cout << "========== iterator test ==========" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "(Bottom)" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "(Top)" << std::endl;

	std::cout << "========== copy test ==========" << std::endl;
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;
	return (0);
}
