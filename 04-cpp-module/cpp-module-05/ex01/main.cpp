/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:08:20 by sshin             #+#    #+#             */
/*   Updated: 2022/02/20 11:00:59 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void test_construct(const std::string& name,
			const int& sign_grade,
			const int& exec_grade)
{
	try
	{
		Form f(name, sign_grade, exec_grade);

		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	Bureaucrat s("Sshin", 1);
	Bureaucrat m("Marvin", 75);
	Form f1("f1", 75, 50);
	Form f2("f2", 30, 30);

	std::cout << s << std::endl
		<< m << std::endl;
	std::cout << std::endl;

	std::cout << f1 << std::endl
		<< f2 << std::endl;
	std::cout << std::endl;

	s.signForm(f1);
	m.signForm(f1);
	s.signForm(f2);
	m.signForm(f2);
	std::cout << std::endl;

	test_construct("f4", 0, 50);
	test_construct("f5", 50, 0);
	test_construct("f6", 151, 50);
	test_construct("f7", 50, 151);
	return (0);
}
