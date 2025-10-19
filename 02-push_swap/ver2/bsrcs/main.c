/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:24:14 by sshin             #+#    #+#             */
/*   Updated: 2021/08/22 14:31:07 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	check_sorted(t_stack **a, t_stack **b, int len)
{
	int		ret_gnl;
	char	*line;

	ret_gnl = get_next_line(STDIN_FILENO, &line);
	while (ret_gnl == 1)
	{
		if (ft_strcmp(line, "Error") == 0)
			terminate();
		c_do_op(line, a, b);
		free(line);
		line = NULL;
		ret_gnl = get_next_line(STDIN_FILENO, &line);
	}
	if (ret_gnl == -1)
		terminate();
	free(line);
	line = NULL;
	if (is_ascnd(*a, len))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	int		len;
	t_stack	*a;
	t_stack	*b;

	if (ac <= 1)
		return (0);
	++av;
	len = get_len_with_null_check(av);
	split_av(&av, len);
	c_init_stack(av, &a, &b);
	clear_av(&av);
	c_check_dup(a);
	check_sorted(&a, &b, len);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
