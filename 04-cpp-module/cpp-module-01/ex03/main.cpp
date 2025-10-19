/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:27:59 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:54:05 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("Crude Spiked Club");
		HumanA bob("Bob", &club);
		bob.attack();
		club.setType("Some other type of Club");
		bob.attack();
	}
	{
		Weapon club = Weapon("Crude Spiked Club");
		HumanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("Some other type of Club");
		jim.attack();
	}
	return (0);
}
