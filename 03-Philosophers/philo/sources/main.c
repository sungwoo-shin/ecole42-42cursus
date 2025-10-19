/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:41:30 by sshin             #+#    #+#             */
/*   Updated: 2021/09/28 20:39:54 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1. Each program is separated into the several branches by pthread_create or fork. The main stream of execution waits the branches by Mutex or Semaphore.
** 2. When the branches separated, each branch makes another execution stream to monitor whether the branch dead or not.
** 3. After making monitoring thread, each branch iterates Taking Fork, Eating, Putting Fork, Sleeping and Thinking.
** 4. pthread_mutex_unlock or sem_post will be called to resume the main stream of execution when the error occurs, philosopher eaten enough and philosopher dead.
** 5. These programs influenced by the time that user typed, exact time measure is important that not to make philosopher dead.
**    usleep function does not make the process or thread sleep with the exact time compare to the argument.
**    When the process or thread has to sleep the xms,usleep function iterates the fraction of the xms inside of the custom made function.
**    This is called as wait_interval in the project.
** 6. To share the beginning time, the main stream of execution measure the time before the branch separation.
** 7. When the action should be printed, each branch should lock the printing resource by pthread_mutex_lock or sem_wait.
*/

#include "philo.h"

static bool	init_info(int ac, char **av, t_info *info)
{
	int	i;

	if (atoi_bool(av[1], &(info->nbr_philo)) == false || \
		atoi_bool(av[2], &(info->time_die)) == false || \
		atoi_bool(av[3], &(info->time_eat)) == false || \
		atoi_bool(av[4], &(info->time_sleep)) == false || \
		(ac == 6 && atoi_bool(av[5], &(info->nbr_eat)) == false))
		return (false);
	info->fork = ft_calloc(info->nbr_philo, sizeof(t_mu));
	if (info->fork == NULL)
		return (false);
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (false);
		++i;
	}
	if (pthread_mutex_init(&info->dining, NULL) || \
		pthread_mutex_init(&info->print, NULL))
		return (false);
	return (true);
}

static void	*routine(void *ptr_ith_philo)
{
	t_philo	*philo;

	philo = (t_philo *)ptr_ith_philo;
	if (timestamp(&philo->cur) == false)
		pthread_mutex_unlock(&philo->info->dining);
	if (philo->i % 2)
		wait_interval(philo, philo->cur, 10 * EPSILON);
	while (1)
	{
		take_fork(philo);
		philo_eat(philo);
		put_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static void	*monitor(void *ptr_ith_philo)
{
	t_philo		*philo;
	long long	cur;

	philo = (t_philo *)ptr_ith_philo;
	if (timestamp(&cur) == false)
		pthread_mutex_unlock(&philo->info->dining);
	wait_interval(philo, cur, philo->info->time_die - EPSILON);
	while (1)
	{
		if (timestamp(&cur) == false)
			pthread_mutex_unlock(&philo->info->dining);
		if (cur - philo->cur >= (long long)philo->info->time_die)
		{
			print_status(DIED, philo);
			pthread_mutex_unlock(&philo->info->dining);
		}
	}
	return (NULL);
}

static bool	feed_philo(t_info *info, t_philo *philo)
{
	int	i;

	if (pthread_mutex_lock(&info->dining) || \
		timestamp(&info->start) == false)
		return (false);
	i = 0;
	while (i < info->nbr_philo)
	{
		philo[i].i = i;
		philo[i].info = info;
		philo[i].l = i;
		philo[i].r = (i + 1) % info->nbr_philo;
		if (pthread_create(&philo[i].routine, NULL, routine, &philo[i]) || \
			pthread_detach(philo[i].routine))
			return (false);
		if (pthread_create(&philo[i].monitor, NULL, monitor, &philo[i]) || \
			pthread_detach(philo[i].monitor))
			return (false);
		++i;
	}
	if (pthread_mutex_lock(&info->dining))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	errno = 0;
	if (!(ac == 5 || ac == 6) || (ac == 6 && ft_atoi(av[5]) == 0))
	{
		print_usage();
		return (terminate(INVALID, NULL));
	}
	info = (t_info){0, };
	if (init_info(ac, av, &info) == false)
	{
		print_usage();
		return (terminate(INVALID, &info));
	}
	philo = ft_calloc(info.nbr_philo, sizeof(t_philo));
	if (philo == NULL)
		return (terminate(INVALID, &info));
	if (feed_philo(&info, philo) == false)
		return (terminate(INVALID, &info));
	return (terminate(VALID, &info));
}
