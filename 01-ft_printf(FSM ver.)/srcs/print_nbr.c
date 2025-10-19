/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:03:04 by snam              #+#    #+#             */
/*   Updated: 2021/10/11 01:00:02 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_nbr_info(size_t *nbr, t_info *info)
{
	info->sign = get_sign(nbr, info->type);
	info->base = get_base(info->type);
	info->nbrlen = get_nbrlen(*nbr, info->base);
}

/*
** print_zero_by_prec 함수의 역할에 대한 설명:
** 정밀도에 의해 추가적으로 '0' 패딩이 필요한 경우 즉, prec >= nbrlen인 경우 '0'을 추가로 패딩한다.
*/

static void	print_zero_by_prec(t_info *info, int len_to_print_nbr)
{
	int	len_to_print_zero;

	len_to_print_zero = len_to_print_nbr - info->nbrlen;
	while (len_to_print_zero > 0)
	{
		info->ret += write(STDOUT_FILENO, "0", 1);
		--len_to_print_zero;
	}
}

static void	print_nbr_by_type(size_t nbr, t_info *info)
{
	char	*buf;
	char	*baseset;
	size_t	nbr_backup;

	if (!(buf = (char *)malloc(sizeof(char) * (info->nbrlen + 1))))
		return ;
	buf[info->nbrlen] = '\0';
	nbr_backup = nbr;
	baseset = get_baseset(info->type);
	while (info->nbrlen > 0)
	{
		buf[info->nbrlen - 1] = baseset[nbr % info->base];
		nbr /= info->base;
		--(info->nbrlen);
	}
	if (!(nbr_backup == 0 && info->prec == 0))
	{
		ft_putstr_fd(buf, STDOUT_FILENO);
		info->ret += ft_strlen(buf);
	}
	free(buf);
}

static void	print_nbr_by_prec(size_t nbr, t_info *info, int len_to_print_nbr)
{
	if (info->sign < 0 && info->flag_zero == false)
		info->ret += write(STDOUT_FILENO, "-", 1);
	print_zero_by_prec(info, len_to_print_nbr);
	if (info->type == 'p')
		info->ret += write(STDOUT_FILENO, "0x", 2);
	print_nbr_by_type(nbr, info);
}

/*
** print_nbr 함수 첫번째 if문의 '!(info->prec == 0 && nbr == 0)' 조건에 대한 설명:
** "정밀도 옵션값이 0인 동시에 가변인자의 값이 0인 경우" 아무것도 출력하지 않아야 한다.
** 이를 구현하기 위해, 해당 조건에서 'len_to_print_nbr'에 'info->nbrlen' 즉, '1'을 할당하지 않고,
** 'info->prec' 즉, '0'을 할당한다.
** 이후 print_nbr_by_type 함수의 마지막 if문에서 해당 조건에서의 출력을 예외처리한다.
*/

void	print_nbr(size_t nbr, t_info *info)
{
	int	len_to_print_nbr;
	int	len_to_print_padding;

	get_nbr_info(&nbr, info);
	if ((info->prec < info->nbrlen) && !(info->prec == 0 && nbr == 0))
		len_to_print_nbr = info->nbrlen;
	else
		len_to_print_nbr = info->prec;
	len_to_print_padding = info->width - len_to_print_nbr;
	if ((info->type == 'd' || info->type == 'i') && info->sign < 0)
		len_to_print_padding -= 1;
	else if (info->type == 'p')
		len_to_print_padding -= 2;
	if (info->sign < 0 && info->flag_zero == true)
		info->ret += write(STDOUT_FILENO, "-", 1);
	if (info->flag_bar == true)
	{
		print_nbr_by_prec(nbr, info, len_to_print_nbr);
		print_padding(info, len_to_print_padding);
	}
	else
	{
		print_padding(info, len_to_print_padding);
		print_nbr_by_prec(nbr, info, len_to_print_nbr);
	}
}
