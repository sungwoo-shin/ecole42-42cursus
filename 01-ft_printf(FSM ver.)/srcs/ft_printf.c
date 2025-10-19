/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:33:49 by snam              #+#    #+#             */
/*   Updated: 2021/10/11 17:01:18 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_token(char input)
{
	if (input == '%')
		return (0);
	else if ('1' <= input && input <= '9')
		return (1);
	else if (input == '\0')
		return (2);
	else if (input == '.')
		return (3);
	else if (input == '*')
		return (4);
	else if (input == '-')
		return (5);
	else if (input == '0')
		return (6);
	else if (input == 'c' || input == 's' || \
		input == 'p' || input == 'd' || input == 'i' || \
		input == 'u' || input == 'x' || input == 'X')
		return (7);
	else
		return (8);
}

static int	get_state(int prv_state, int token)
{
	int	state_trans_table[81] = {2, 1, 10, 1, 1, 1, 1, 1, 1, \
								2, 1, 10, 1, 1, 1, 1, 1, 1, \
								8, 3, -1, 5, 4, 2, 2, 8, -1, \
								8, 3, -1, 5, -1, -1, 3, 8, -1, \
								8, -1, -1, 5, -1, -1, -1, 8, -1, \
								8, 6, -1, -1, 7, -1, 6, 8, -1, \
								8, 6, -1, -1, -1, -1, 6, 8, -1, \
								8, -1, -1, -1, -1, -1, -1, 8, -1};
	return (state_trans_table[(9 * prv_state) + token]);
}

static void	process(char input, t_info *info, int *state)
{
	if (*state == 1)
		ft_putchar(input, info);
	else if (*state == 2)
		process_2(input, info);
	else if (*state == 3)
		process_3(input, info);
	else if (*state == 4)
		process_4(info);
	else if (*state == 5)
		info->prec = 0;
	else if (*state == 6)
		process_6(input, info);
	else if (*state == 7)
		process_7(info);
	else if (*state == 8)
	{
		*state = 0;
		info->type = input;
		process_8(info);
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_info	info;
	int		state;
	int		prv_state;
	int		token;

	va_start(info.ap, fmt);
	reset_info(&info);
	info.ret = 0;
	state = 0;
	while (*fmt && state != 10)
	{
		prv_state = state;
		token = get_token(*fmt);
		state = get_state(prv_state, token);
		if (state == -1)
			return (0);
		process(*fmt, &info, &state);
		++fmt;
	}
	va_end(info.ap);
	return (info.ret);
}

void	reset_info(t_info *info)
{
	info->flag_bar = false;
	info->flag_zero = false;
	info->width = 0;
	info->prec = -1;
}
