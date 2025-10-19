/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:14:42 by sshin             #+#    #+#             */
/*   Updated: 2021/09/21 02:14:52 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		++cnt;
		++str;
	}
	return (cnt);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

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
