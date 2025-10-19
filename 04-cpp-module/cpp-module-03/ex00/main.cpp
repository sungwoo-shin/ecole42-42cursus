/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:24:20 by sshin             #+#    #+#             */
/*   Updated: 2022/02/17 17:47:24 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string s1 = "sshin";
	std::string s2 = "cadet";

	ClapTrap c1(s1);
	ClapTrap c2(s2);

	std::cout << std::endl;
	c1.beRepaired(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.attack(s2);
	c2.takeDamage(5);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.beRepaired(3);
	c2.beRepaired(2);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(s1);
	c1.takeDamage(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.beRepaired(10);
	c1.attack(s2);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(s1);
	c1.takeDamage(5);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.print_status(std::cout);
	c2.print_status(std::cout);
	std::cout << std::endl;
	return (0);
}
