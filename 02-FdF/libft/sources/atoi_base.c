/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:48:26 by sshin             #+#    #+#             */
/*   Updated: 2021/08/17 16:57:49 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	has_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i] != '0')
			return (false);
		++i;
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (true);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (true);
		if (base == 8)
			return (true);
	}
	return (false);
}

static int	get_digit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		++i;
	}
	return (-1);
}

int	atoi_base(const char *str, int base)
{
	size_t	i;
	size_t	ret;
	int		sign;

	i = 0;
	while (is_spc(str[i]))
		++i;
	if (base != 10 && has_prefix(&str[i], base) == false)
		return (false);
	sign = 1;
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		++i;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	ret = 0;
	while (get_digit_base(str[i], base) >= 0)
	{
		ret = ret * base + get_digit_base(str[i], base);
		++i;
	}
	return ((int)(sign * ret));
}
