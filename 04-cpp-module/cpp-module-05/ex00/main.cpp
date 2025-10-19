/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:08:23 by sshin             #+#    #+#             */
/*   Updated: 2022/02/19 21:21:21 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test_increase(void)
{
	Bureaucrat s("Sshin", 1);
	Bureaucrat m("Marvin", 150);

	std::cout << s << std::endl;
	std::cout << m << std::endl;
	std::cout << std::endl;

	try
	{
		s.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		m.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test_construct(void)
{
	try
	{
		Bureaucrat s("sshin", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat m("marvin", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	test_increase();
	std::cout << std::endl;
	test_construct();
	return (0);
}

/*
**                 exception
**                 /       \
** GradeTooHighException   GradeTooLowException
*/
