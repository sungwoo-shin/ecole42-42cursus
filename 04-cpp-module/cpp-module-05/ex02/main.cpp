/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:19:47 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:11:13 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("Sshin", 1);
	Bureaucrat b2("Marvin", 150);

	Form* f1 = new ShrubberyCreationForm("Home");
	Form* f2 = new RobotomyRequestForm("Wall-E");
	Form* f3 = new PresidentialPardonForm("Theif");

	std::cout << b1 << std::endl
		<< b2 << std::endl;
	std::cout << std::endl;

	std::cout << *f1 << std::endl
		<< *f2 << std::endl
		<< *f3 << std::endl;
	std::cout << std::endl;

	b2.signForm(*f1);
	b2.signForm(*f2);
	b2.signForm(*f3);
	std::cout << std::endl;

	b1.signForm(*f1);
	b1.signForm(*f2);
	b1.signForm(*f3);
	std::cout << std::endl;

	b2.executeForm(*f1);
	b2.executeForm(*f2);
	b2.executeForm(*f3);
	std::cout << std::endl;

	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;
	return (0);
}

/*
** Form: beSigned(), checkExecutable()
** - ShrubberyCreationForm: execute()
** - RobotomyRequestForm: execute()
** - PresidentialPardonForm: execute()
*/
