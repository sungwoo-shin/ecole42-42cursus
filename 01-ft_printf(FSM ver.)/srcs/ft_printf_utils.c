/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:50:42 by snam              #+#    #+#             */
/*   Updated: 2021/10/17 21:39:15 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_info *info)
{
	write(1, &c, 1);
	++(info->ret);
}

int		get_sign(size_t *nbr, char type)
{
	if ((type == 'd' || type == 'i') && (int)*nbr < 0)
	{
		*nbr *= -1;
		return (-1);
	}
	return (1);
}

int		get_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return (10);
	else
		return (16);
}

int		get_nbrlen(size_t nbr, int base)
{
	int		len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		++len;
		nbr /= base;
	}
	return (len);
}

char	*get_baseset(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

/*
** Library functions
*/

size_t	ft_strlen(const char *str)
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
