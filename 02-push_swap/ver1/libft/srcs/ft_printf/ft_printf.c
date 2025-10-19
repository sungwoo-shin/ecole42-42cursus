/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:52:05 by sshin             #+#    #+#             */
/*   Updated: 2021/06/25 10:40:30 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			ret;
	t_info		info;

	va_start(ap, fmt);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt; // skip '%'
			parse_fmt(&fmt, ap, &info);
			ret += print_by_type(ap, &info);
		}
		else
			ret += write(STDOUT, fmt, 1);
		++fmt;
	}
	va_end(ap);
	return (ret);
}

void	parse_fmt(const char **fmt, va_list ap, t_info *info)
{
	const char *m_type;

	init_opt_info(info);
	m_type = "cspdiuxX%";
	while (ft_strchr(m_type, **fmt) == NULL)
	{
		get_opt_info(**fmt, ap, info);
		++(*fmt);
	}
	if ((info->m_minus == true || info->m_prec > -1))
		info->m_zero = false;
	info->m_type = **fmt;
}

void	get_opt_info(const char fmt, va_list ap, t_info *info)
{
	if (fmt == '0' && info->m_width == 0 && info->m_prec == -1)
		info->m_zero = true;
	else if (fmt == '-' && info->m_prec == -1)
		info->m_minus = true;
	else if (fmt == '.')
		info->m_prec = 0;
	else if (ft_isdigit(fmt))
		get_digit_info(fmt, info);
	else if (fmt == '*')
		get_aster_info(ap, info);
}

void	get_digit_info(const char fmt, t_info *info)
{
	if (info->m_prec == -1)
		info->m_width = info->m_width * 10 + (fmt - 48);
	else
		info->m_prec = info->m_prec * 10 + (fmt - 48);
}

void	get_aster_info(va_list ap, t_info *info)
{
	if (info->m_prec == -1)
	{
		info->m_width = va_arg(ap, int);
		if (info->m_width < 0)
		{
			info->m_minus = true;
			info->m_width *= -1;
		}
	}
	else
		info->m_prec = va_arg(ap, int);
}
