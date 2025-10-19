/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:19:35 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:19:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data d("Macbook Pro", 2141, 2799.0, 2000.0);
	std::cout << &d << std::endl << std::endl;
	std::cout << d;

	uintptr_t p = serialize(&d);
	print_spec(p);
	return (0);
}

/*
** &d1 -> serialize(reinterpret_cast<uintptr_t) -> p1
** -> deserialize(reinterpret_cast<Data*>) -> == &d1?
*/
