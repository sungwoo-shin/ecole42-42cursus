/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:52:01 by sshin             #+#    #+#             */
/*   Updated: 2021/09/25 18:36:42 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	timestamp(long long *time_to_stamp)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (false);
	*time_to_stamp = (long long)(tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	return (true);
}

void	wait_interval(t_info *info, long long start, long long interval)
{
	long long	cur;

	while (1)
	{
		if (timestamp(&cur) == false)
			sem_post(info->sem_dining);
		if (cur - start >= interval)
			break ;
		if (usleep(EPSILON) == ERROR)
			sem_post(info->sem_dining);
	}
}
