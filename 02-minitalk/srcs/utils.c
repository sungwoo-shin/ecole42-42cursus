/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:47:36 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 22:53:38 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	terminate(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

bool	get_jth_bit(char buf, int j)
{
	char	bit_mask;

	bit_mask = 1 << (7 - j);
	return (buf & bit_mask);
}
