/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_int_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:19:19 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:35:46 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static bool	is_plusminus(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

static bool	is_nbr(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

static void	apply_sign(int sign, long long *ret)
{
	if (sign < 0)
		*ret = ~(*ret) + 1;
}

int	atoi_with_int_check(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	if (is_plusminus(*str))
	{
		if (*str == '-')
			sign = ~(sign) + 1;
		++str;
	}
	ret = 0;
	while (*str)
	{
		if (is_nbr(*str))
		{
			ret *= 10;
			ret += (*str - '0');
		}
		else
			terminate();
		++str;
	}
	apply_sign(sign, &ret);
	if (ret < INT_MIN || INT_MAX < ret)
		terminate();
	return (ret);
}
