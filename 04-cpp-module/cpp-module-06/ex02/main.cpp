/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:19:42 by sshin             #+#    #+#             */
/*   Updated: 2022/02/24 18:19:43 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	for (int i = 0; i < 5; ++i)
	{
		Base* base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}

/*
**   Base
**  /  |  \
** A   B   C
**  (empty)
*/
