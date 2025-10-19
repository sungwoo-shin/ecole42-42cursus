/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:18:18 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:03:44 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::string s1 = "sshin";
	std::string s2 = "cadet";
	std::string s3 = "marvin";

	ScavTrap t1(s1);
	ScavTrap t2(s2);
	ClapTrap t3(s3);

	std::cout << std::endl;
	t1.attack(s3);
	t3.takeDamage(t1.getAD());
	t3.takeDamage(t1.getAD());
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(s2);
	t2.takeDamage(t1.getAD());
	t2.beRepaired(t1.getAD() / 2);
	t2.beRepaired(t1.getAD() / 2);
	t2.beRepaired(t1.getAD() / 2);
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(s3);
	t2.takeDamage(t1.getAD());
	t1.attack(s3);
	t2.takeDamage(t1.getAD());
	t1.attack(s3);
	t2.takeDamage(t1.getAD());
	std::cout << std::endl;

	std::cout << std::endl;
	t2.guardGate();
	std::cout << std::endl;

	t1.print_status(std::cout);
	t2.print_status(std::cout);
	t3.print_status(std::cout);
	return (0);
}
