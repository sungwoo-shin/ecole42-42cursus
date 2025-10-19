/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:29:12 by sshin             #+#    #+#             */
/*   Updated: 2021/08/31 19:07:42 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

static int	g_received_signal;

static void	handler(int signo)
{
	if (signo == SIGUSR1)
		g_received_signal = 1;
	else if (signo == SIGUSR2)
		g_received_signal = 0;
	else
		g_received_signal = -1;
}

static void	send_null(pid_t pid_server)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		kill(pid_server, SIGUSR2);
		pause();
		if (g_received_signal != 0)
			terminate();
		++i;
	}
}

static int	get_signal(char buf, int j)
{
	int	signal;

	if (get_jth_bit(buf, j) == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	return (signal);
}

#include <time.h>
#include <stdio.h>

static void	send_msg(pid_t pid_server, char *str)
{
	int		i;
	int		j;
	int		signal;
	char	buf;

	pause();
	clock_t s = clock(); // timer
	i = 0;
	while (str[i])
	{
		buf = str[i];
		j = 0;
		while (j < 8)
		{
			signal = get_signal(buf, j);
			usleep(50);
			kill(pid_server, signal);
			pause();
			if ((get_jth_bit(buf, j) != g_received_signal))
				terminate();
			++j;
		}
		++i;
	}
	send_null(pid_server);
	ft_putstr_fd("Minitalk succeeded!\n", STDOUT_FILENO);
	clock_t f = clock(); // timer
	printf("Duration: %lf [sec]\n", (double)(f - s)/CLOCKS_PER_SEC); // timer
}

int	main(int ac, char *av[])
{
	if (ac != 3 || PID_MAX < ft_atoi(av[1]) || av[2][0] == '\0')
		terminate();
	ft_putstr_fd("Client PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_msg(ft_atoi(av[1]), av[2]);
}
