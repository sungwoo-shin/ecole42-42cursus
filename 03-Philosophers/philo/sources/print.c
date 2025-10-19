/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:54:52 by sshin             #+#    #+#             */
/*   Updated: 2021/09/30 12:14:05 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "color.h"

static void	print_msg(t_status status)
{
	if (status == TAKEN)
	{
		ft_putstr_fd(BYEL, STDOUT_FILENO);
		ft_putendl_fd(" has taken a fork", STDOUT_FILENO);
	}
	else if (status == EATING)
	{
		ft_putstr_fd(BRED, STDOUT_FILENO);
		ft_putendl_fd(" is eating", STDOUT_FILENO);
	}
	else if (status == SLEEPING)
	{
		ft_putstr_fd(CYN, STDOUT_FILENO);
		ft_putendl_fd(" is sleeping", STDOUT_FILENO);
	}
	else if (status == THINKING)
	{
		ft_putstr_fd(BBLU, STDOUT_FILENO);
		ft_putendl_fd(" is thinking", STDOUT_FILENO);
	}
	else if (status == DIED)
	{
		ft_putstr_fd(RED, STDOUT_FILENO);
		ft_putendl_fd(" died", STDOUT_FILENO);
	}
}

bool	print_status(t_status status, t_philo *philo)
{
	long long	cur;

	if (pthread_mutex_lock(&philo->info->print) || \
		timestamp(&cur) == false)
		return (false);
	ft_putnbr_fd(cur - philo->info->start, STDOUT_FILENO);
	if (status == COMPLETE)
	{
		ft_putstr_fd(BWHT, STDOUT_FILENO);
		ft_putendl_fd("\tDining Philosophers simulation complete!", 1);
		ft_putstr_fd(EOC, STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd("\t", STDOUT_FILENO);
		ft_putstr_fd(BWHT, STDOUT_FILENO);
		ft_putnbr_fd(philo->i + 1, STDOUT_FILENO);
		print_msg(status);
		ft_putstr_fd(EOC, STDOUT_FILENO);
	}
	if (status == DIED || status == COMPLETE)
		return (false);
	if (pthread_mutex_unlock(&philo->info->print))
		return (false);
	return (true);
}
