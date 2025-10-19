/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:44:24 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 19:03:38 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal *wrong_cat = new WrongCat();

	std::cout << std::endl;
	wrong_cat->makeSound();
	std::cout << std::endl;

	delete meta;
	delete cat;
	delete dog;
	delete wrong_cat;
	return (0);
}
