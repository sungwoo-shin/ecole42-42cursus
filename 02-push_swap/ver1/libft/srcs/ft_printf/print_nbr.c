/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:10:34 by sshin             #+#    #+#             */
/*   Updated: 2021/06/24 14:34:00 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print_nbr 함수 첫번째 if문의 '!(info->prec == 0 && nbr == 0)' 조건에 대한 설명:
// "정밀도 옵션값이 0인 동시에 가변인자의 값이 0인 경우" 아무것도 출력하지 않아야 한다.
// 이를 구현하기 위해, 해당 조건에서 'len_to_print_nbr'에 'info->m_nbrlen' 즉, '1'을 할당하지 않고,
// 'info->prec' 즉, '0'을 할당한다.
// 이후 print_nbr_by_type 함수의 마지막 if문에서 해당 조건에서의 출력을 예외처리한다.
int		print_nbr(size_t nbr, t_info *info)
{
	int		len_to_print_nbr;
	int		len_to_print_padding;
	int		ret;

	get_nbr_info(&nbr, info);
	if ((info->m_prec < info->m_nbrlen) && !(info->m_prec == 0 && nbr == 0))
		len_to_print_nbr = info->m_nbrlen;
	else
		len_to_print_nbr = info->m_prec;
	len_to_print_padding = info->m_width - len_to_print_nbr;
	if ((info->m_type == 'd' || info->m_type == 'i') && info->m_sign < 0)
		len_to_print_padding -= 1;
	else if (info->m_type == 'p')
		len_to_print_padding -= 2;
	ret = 0;
	if (info->m_sign < 0 && info->m_zero == true)
		ret += write(STDOUT, "-", 1);
	if (info->m_minus == true)
	{
		ret += print_nbr_by_prec(nbr, info, len_to_print_nbr);
		ret += print_padding(info, len_to_print_padding);
	}
	else
	{
		ret += print_padding(info, len_to_print_padding);
		ret += print_nbr_by_prec(nbr, info, len_to_print_nbr);
	}
	return (ret);
}

inline void	get_nbr_info(size_t *nbr, t_info *info)
{
	info->m_sign = get_sign(nbr, info->m_type);
	info->m_base = get_base(info->m_type);
	info->m_nbrlen = get_nbrlen(*nbr, info->m_base);
}

int		print_nbr_by_prec(size_t nbr, t_info *info, int len_to_print_nbr)
{
	int		ret;

	ret = 0;
	if (info->m_sign < 0 && info->m_zero == false)
		ret += write(STDOUT, "-", 1);
	ret += print_zero_by_prec(info, len_to_print_nbr);
	if (info->m_type == 'p')
		ret += write(STDOUT, "0x", 2);
	ret += print_nbr_by_type(nbr, info);
	return (ret);
}

// print_zero_by_prec 함수의 역할에 대한 설명:
// 정밀도에 의해 추가적으로 '0' 패딩이 필요한 경우 즉, m_prec >= m_nbrlen인 경우 '0'을 추가로 패딩한다.
int		print_zero_by_prec(t_info *info, int len_to_print_nbr)
{
	int		len_to_print_zero;
	int		ret;

	len_to_print_zero = len_to_print_nbr - info->m_nbrlen;
	ret = 0;
	while (len_to_print_zero > 0)
	{
		ret += write(STDOUT, "0", 1);
		--len_to_print_zero;
	}
	return (ret);
}

int		print_nbr_by_type(size_t nbr, t_info *info)
{
	char		*buf;
	char		*baseset;
	size_t		nbr_backup;
	int			ret;

	if (!(buf = (char *)malloc(sizeof(char) * (info->m_nbrlen + 1))))
		return (0);
	buf[info->m_nbrlen] = '\0';
	nbr_backup = nbr;
	baseset = get_baseset(info->m_type);
	while (info->m_nbrlen > 0)
	{
		buf[info->m_nbrlen - 1] = baseset[nbr % info->m_base];
		nbr /= info->m_base;
		--(info->m_nbrlen);
	}
	ret = 0;
	if (!(nbr_backup == 0 && info->m_prec == 0))
	{
		ft_putstr_fd(buf, STDOUT);
		ret += ft_strlen(buf);
	}
	free(buf);
	return (ret);
}
