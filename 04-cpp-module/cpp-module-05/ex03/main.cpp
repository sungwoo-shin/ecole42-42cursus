/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:19:14 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:19:14 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	Intern i;
	Bureaucrat b1("Sshin", 1);
	Bureaucrat b2("Marvin", 150);

	Form* f1 = i.makeForm(S_FORM, "Home");
	Form* f2 = i.makeForm(R_FORM, "Wall-E");
	Form* f3 = i.makeForm(P_FORM, "Theif");
	i.makeForm("Wrong", "Wrong");
	if (!f1 || !f2 || !f3)
		return (1);
	std::cout << std::endl;

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
