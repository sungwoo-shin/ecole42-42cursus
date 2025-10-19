/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:50:04 by snam              #+#    #+#             */
/*   Updated: 2021/10/11 17:01:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, t_info *info)
{
	int	len_to_print_padding;

	len_to_print_padding = info->width - 1;
	if (info->flag_bar == true)
	{
		ft_putchar(c, info);
		print_padding(info, len_to_print_padding);
	}
	else
	{
		print_padding(info, len_to_print_padding);
		ft_putchar(c, info);
	}
}

static void	print_str_by_prec(t_info *info, char *str, int len_to_print_str)
{
	int	i;

	i = 0;
	while (i < len_to_print_str)
	{
		ft_putchar(str[i], info);
		++i;
	}
}

void	print_str(char *str, t_info *info)
{
	int	len_to_print_str;
	int	len_to_print_padding;

	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		len_to_print_str = ft_strlen(str);
	else
		len_to_print_str = info->prec;
	len_to_print_padding = info->width - len_to_print_str;
	if (info->flag_bar == true)
	{
		print_str_by_prec(info, str, len_to_print_str);
		print_padding(info, len_to_print_padding);
	}
	else
	{
		print_padding(info, len_to_print_padding);
		print_str_by_prec(info, str, len_to_print_str);
	}
}

void	print_padding(t_info *info, int len_to_print_padding)
{
	char	padding;

	padding = (info->flag_zero == true && info->type != 's') ? '0' : ' ';
	if (info->flag_zero == true && \
		(info->type == '%' && info->flag_bar == true))
		padding = ' ';
	while (len_to_print_padding > 0)
	{
		ft_putchar(padding, info);
		--len_to_print_padding;
	}
}
