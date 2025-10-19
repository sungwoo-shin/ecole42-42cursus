/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:52:14 by sshin             #+#    #+#             */
/*   Updated: 2021/09/29 15:04:55 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_usage(void)
{
	ft_putstr_fd("usage : ./philo number_of_philosophers ", STDERR_FILENO);
	ft_putstr_fd("time_to_die time_to_eat time_to_sleep ", STDERR_FILENO);
	ft_putendl_fd("[number_of_times_each_philosopher_must_eat]", STDERR_FILENO);
}

static void	unlink_sem(t_info *info)
{
	int	i;

	sem_unlink(info->dining);
	sem_unlink(info->fork);
	sem_unlink(info->print);
	sem_unlink(info->full);
	i = 0;
	if (info->philo)
	{
		while (info->philo[i].pid && i < info->nbr_philo)
		{
			kill(info->philo[i].pid, SIGKILL);
			waitpid(info->philo[i].pid, NULL, WNOHANG);
			++i;
		}
	}
}

t_exit	terminate(int validation, t_info *info)
{
	if (info)
		unlink_sem(info);
	if (errno != 0 && errno != 2)
		perror("philo_bonus");
	if (validation == INVALID)
		return (INVALID);
	else
		return (VALID);
}
