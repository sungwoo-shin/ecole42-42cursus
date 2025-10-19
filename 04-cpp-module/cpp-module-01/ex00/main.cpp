/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:43:54 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 17:52:13 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *z[NB_ZOMBIE];

	std::cout << "Creating " << NB_ZOMBIE << " Random Stack Zombies"
		<< std::endl << std::endl;
	for (int i = 0; i < NB_ZOMBIE; ++i)
		Zombie::randomChump(Zombie::get_rnd_name());

	std::cout << std::endl << "Creating " << NB_ZOMBIE << " Random Heap Zombies"
		<< std::endl << std::endl;
	for (int i = 0; i < NB_ZOMBIE; ++i)
		z[i] = Zombie::newZombie(Zombie::get_rnd_name());

	std::cout << std::endl << "Destroying " << NB_ZOMBIE << " Random Heap Zombies"
		<< std::endl << std::endl;
	for (int i = 0; i < NB_ZOMBIE; ++i)
		delete z[i];
	return (0);
}
