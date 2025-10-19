/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:44:18 by swshin            #+#    #+#             */
/*   Updated: 2021/06/24 14:17:06 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_opt_info(t_info *info)
{
	info->m_minus = false;
	info->m_zero = false;
	info->m_width = 0;
	info->m_prec = -1;
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
