/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:54:42 by sshin             #+#    #+#             */
/*   Updated: 2021/05/23 12:15:01 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspc(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

static int	ft_isnbr(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static int	ft_isoper(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		sign;
	size_t	ret;

	sign = 1;
	ret = 0;
	while (ft_isspc(*str))
		++str;
	if (ft_isoper(*str))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (ft_isnbr(*str))
	{
		ret *= 10;
		ret += (*str - '0');
		++str;
	}
	if (sign > 0 && ret > 9223372036854775807llu)
		return (-1);
	if (sign < 0 && ret > 9223372036854775808llu)
		return (0);
	return (sign * ((int)ret));
}
