/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:27:26 by sshin             #+#    #+#             */
/*   Updated: 2021/09/21 21:53:28 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	timestamp(long long *time_to_stamp)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (false);
	*time_to_stamp = (long long)(tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	return (true);
}

void	wait_interval(t_philo *philo, long long start, long long interval)
{
	long long	cur;

	while (1)
	{
		if (timestamp(&cur) == false)
			pthread_mutex_unlock(&philo->info->dining);
		if (cur - start >= interval)
			break ;
		if (usleep(EPSILON) == ERROR)
			pthread_mutex_unlock(&philo->info->dining);
	}
}
