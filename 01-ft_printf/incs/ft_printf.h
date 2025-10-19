/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:52:08 by sshin             #+#    #+#             */
/*   Updated: 2021/09/26 21:31:11 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/incs/libft.h"

typedef struct	s_info
{
	bool	m_minus;
	bool	m_zero;
	int		m_width;
	int		m_prec;
	char	m_type;
	int		m_sign;
	int		m_base;
	int		m_nbrlen;
}				t_info;

/*
** =============================================================================
** ft_printf.c
** =============================================================================
*/

int				ft_printf(const char *fmt, ...);

/*
** =============================================================================
** print_by_type.c
** =============================================================================
*/

int				print_by_type(va_list ap, t_info *info);
int				print_padding(t_info *info, int len_to_print_padding);

/*
** =============================================================================
** print_nbr.c
** =============================================================================
*/

int				print_nbr(size_t nbr, t_info *info);

/*
** =============================================================================
** ft_printf_utils.c
** =============================================================================
*/

void			init_opt_info(t_info *info);
int				get_sign(size_t *nbr, char type);
int				get_base(char type);
char			*get_baseset(char type);
int				get_nbrlen(size_t nbr, int base);

#endif
