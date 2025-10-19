/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:23:46 by sshin             #+#    #+#             */
/*   Updated: 2021/05/23 12:05:49 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	long_n;
	int			i;
	char		buf[42];

	if (fd < 0)
		return ;
	long_n = n;
	if (long_n == 0)
		write(fd, "0", 1);
	if (long_n < 0)
	{
		write(fd, "-", 1);
		long_n *= -1;
	}
	i = 0;
	while (long_n)
	{
		buf[i] = long_n % 10 + '0';
		long_n /= 10;
		++i;
	}
	while (i-- > 0)
		write(fd, &buf[i], 1);
}
