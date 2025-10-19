/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:10:24 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:52:08 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating a Horde of " << NB_ZOMBIE << " Zombies ..."
	<< std::endl << std::endl;
	Zombie *z = Zombie::zombieHorde(NB_ZOMBIE);

	std::cout << std::endl << "Destroying a Horde of " << NB_ZOMBIE << " Zombies ..."
	<< std::endl << std::endl;
	delete[] z;
	return (0);
}
