/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:08:48 by sshin             #+#    #+#             */
/*   Updated: 2021/06/24 14:34:04 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_by_type(va_list ap, t_info *info)
{
	if (info->m_type == 'c')
		return (print_char(va_arg(ap, int), info));
	else if (info->m_type == 's')
		return (print_str(va_arg(ap, char *), info));
	else if (info->m_type == 'p')
		return (print_nbr(va_arg(ap, unsigned long), info));
	else if (info->m_type == 'd' || info->m_type == 'i')
		return (print_nbr(va_arg(ap, int), info));
	else if (info->m_type == 'u' || info->m_type == 'x' || info->m_type == 'X')
		return (print_nbr(va_arg(ap, unsigned int), info));
	else // info->m_type == '%'
		return (print_char('%', info));
}

int		print_char(char c, t_info *info)
{
	int		len_to_print_padding;
	int		ret;

	len_to_print_padding = info->m_width - 1;
	ret = 0;
	if (info->m_minus == true)
	{
		ret += write(STDOUT, &c, 1);
		ret += print_padding(info, len_to_print_padding);
	}
	else
	{
		ret += print_padding(info, len_to_print_padding);
		ret += write(STDOUT, &c, 1);
	}
	return (ret);
}

int		print_padding(t_info *info, int len_to_print_padding)
{
	char	padding;
	int		ret;

	padding = (info->m_zero == true && info->m_type != 's') ? '0' : ' ';
	ret = 0;
	while (len_to_print_padding > 0)
	{
		ret += write(STDOUT, &padding, 1);
		--len_to_print_padding;
	}
	return (ret);
}

int		print_str(char *str, t_info *info)
{
	int		len_to_print_str;
	int		len_to_print_padding;
	int		ret;

	if (str == NULL)
		str = "(null)";
	if (info->m_prec == -1 || (size_t)info->m_prec > ft_strlen(str))
		len_to_print_str = ft_strlen(str);
	else
		len_to_print_str = info->m_prec;
	len_to_print_padding = info->m_width - len_to_print_str;
	ret = 0;
	if (info->m_minus == true)
	{
		ret += print_str_by_prec(str, len_to_print_str);
		ret += print_padding(info, len_to_print_padding);
	}
	else
	{
		ret += print_padding(info, len_to_print_padding);
		ret += print_str_by_prec(str, len_to_print_str);
	}
	return (ret);
}

int		print_str_by_prec(char *str, int len_to_print_str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < len_to_print_str)
	{
		ret += write(STDOUT, &str[i], 1);
		++i;
	}
	return (ret);
}
