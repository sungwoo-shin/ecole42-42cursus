/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:29:12 by sshin             #+#    #+#             */
/*   Updated: 2021/08/31 19:07:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

static t_msg	g_msg;

static void	init_msg(void)
{
	int		ret_gnl;
	char	*line;

	g_msg = (t_msg){0, };
	ft_putstr_fd("Enter client PID:\n", STDOUT_FILENO);
	ret_gnl = get_next_line(STDIN_FILENO, &line);
	if (ret_gnl != 1)
		terminate();
	g_msg.pid_client = ft_atoi(line);
	free(line);
	line = NULL;
	kill(g_msg.pid_client, SIGUSR1);
}

static char	*init_content(char c)
{
	char	*content;

	content = (char *)malloc(sizeof(char) * 1);
	if (content == NULL)
		terminate();
	*content = c;
	return (content);
}

static void	print_msg(void)
{
	t_list	*cur;

	ft_putstr_fd("Received message: >>", STDOUT_FILENO);
	cur = g_msg.lst;
	while (cur)
	{
		ft_putchar_fd(*((char *)cur->content), STDOUT_FILENO);
		cur = cur->next;
	}
	ft_putstr_fd("<<\n", STDOUT_FILENO);
}

static void	handler(int signo)
{
	int	signal;

	++g_msg.cnt_bit;
	g_msg.buf = (g_msg.buf << 1) | (signo == SIGUSR1);
	if (signo == SIGUSR1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	usleep(50);
	kill(g_msg.pid_client, signal);
	if (g_msg.cnt_bit == 8)
	{
		ft_lstadd_back(&g_msg.lst, ft_lstnew(init_content(g_msg.buf)));
		if (g_msg.buf == '\0')
		{
			print_msg();
			ft_lstclear(&g_msg.lst, free);
			init_msg();
		}
		g_msg.cnt_bit = 0;
		g_msg.buf = '\0';
	}
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	init_msg();
	while (1)
	{
		pause();
	}
}
