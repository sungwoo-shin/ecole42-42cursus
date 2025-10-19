/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:37:30 by sshin             #+#    #+#             */
/*   Updated: 2021/05/13 15:49:12 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_intlen(int n)
{
	int	len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*ret;

	len = ft_intlen(n);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	sign = 0;
	if (n < 0)
		sign = 1;
	while (--len >= sign)
	{
		ret[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	if (sign)
		ret[0] = '-';
	return (ret);
}
