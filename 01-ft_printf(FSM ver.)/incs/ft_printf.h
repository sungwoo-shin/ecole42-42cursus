/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 01:49:29 by snam              #+#    #+#             */
/*   Updated: 2021/10/11 01:07:16 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_info
{
	bool		flag_bar;
	bool		flag_zero;
	int			width;
	int			prec;
	int			sign;
	int			base;
	int			nbrlen;
	int			ret;
	char		type;
	va_list		ap;
}				t_info;

/*
** =============================================================================
** ft_printf.c
** =============================================================================
*/

int		ft_printf(const char *, ...);
void	reset_info(t_info *);

/*
** =============================================================================
** process.c
** =============================================================================
*/

void	process_2(char, t_info *);
void	process_3(char, t_info *);
void	process_4(t_info *);
void	process_6(char, t_info *);
void	process_7(t_info *);
void	process_8(t_info *);

/*
** =============================================================================
** print_letter.c
** =============================================================================
*/

void	print_char(char, t_info *);
void	print_str(char *, t_info *);
void	print_padding(t_info *, int);

/*
** =============================================================================
** print_nbr.c
** =============================================================================
*/

void	print_nbr(size_t, t_info *);

/*
** =============================================================================
** ft_printf_utils.c
** =============================================================================
*/

void	ft_putchar(char, t_info *);
int		get_sign(size_t *, char);
int		get_base(char);
char	*get_baseset(char);
int		get_nbrlen(size_t, int);
size_t	ft_strlen(const char *);
void	ft_putstr_fd(char *, int);

#endif
