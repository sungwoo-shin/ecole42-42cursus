/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:33:56 by snam              #+#    #+#             */
/*   Updated: 2021/10/11 17:02:21 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_2(char input, t_info *info)
{
	if (input == '-')
		info->flag_bar = 1;
	else if (input == '0')
		info->flag_zero = 1;
}

void	process_3(char input, t_info *info)
{
	info->width *= 10;
	info->width += (input - '0');
}

void	process_4(t_info *info)
{
	int	arg;

	arg = va_arg(info->ap, int);
	if (arg < 0)
	{
		info->flag_bar = true;
		info->width = -arg;
	}
	else
		info->width = arg;
}

void	process_6(char input, t_info *info)
{
	info->prec *= 10;
	info->prec += (input - '0');
}

void	process_7(t_info *info)
{
	int	arg;

	arg = va_arg(info->ap, int);
	info->prec = arg;
}

void	process_8(t_info *info)
{
	if ((info->flag_bar == true || info->prec > -1))
		info->flag_zero = false;
	if (info->type == 'c')
		print_char(va_arg(info->ap, int), info);
	else if (info->type == 's')
		print_str(va_arg(info->ap, char *), info);
	else if (info->type == 'p')
		print_nbr(va_arg(info->ap, unsigned long), info);
	else if (info->type == 'd' || info->type == 'i')
		print_nbr(va_arg(info->ap, int), info);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		print_nbr(va_arg(info->ap, unsigned int), info);
	else if (info->type == '%')
		print_char('%', info);
	reset_info(info);
}
