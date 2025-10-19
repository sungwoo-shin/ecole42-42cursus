/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_int_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:19:19 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:03:50 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	atoi_with_int_check(const char *str, t_stack *a)
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
			handle_error(a);
		++str;
	}
	apply_sign(sign, &ret);
	check_int(ret, a);
	return (ret);
}

bool	is_plusminus(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

bool	is_nbr(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

void	apply_sign(int sign, long long *ret)
{
	if (sign < 0)
		*ret = ~(*ret) + 1;
}

void	check_int(long long ret, t_stack *a)
{
	if (ret < INT_MIN || INT_MAX < ret)
		handle_error(a);
	return ;
}
