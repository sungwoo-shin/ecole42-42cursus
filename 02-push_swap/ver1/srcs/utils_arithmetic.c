/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:57:28 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:05:21 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	handle_error(t_stack *a)
{
	clear_lst(a);
	write(2, "Error\n", 6);
	exit(1);
}

bool	is_dscnd(t_stack *head, int len)
{
	while (len > 1)
	{
		if (head->val < head->nxt->val)
			return (false);
		head = head->nxt;
		--len;
	}
	return (true);
}

bool	is_ascnd(t_stack *head, int len)
{
	while (len > 1)
	{
		if (head->val > head->nxt->val)
			return (false);
		head = head->nxt;
		--len;
	}
	return (true);
}

int	get_min_val(t_stack *head)
{
	t_stack	*backup;
	int		min;

	backup = head;
	min = head->val;
	while (1)
	{
		if (min > head->nxt->val)
			min = head->nxt->val;
		head = head->nxt;
		if (head == backup)
			break ;
	}
	return (min);
}

int	get_max_val(t_stack *head)
{
	t_stack	*backup;
	int		max;

	backup = head;
	max = head->val;
	while (1)
	{
		if (max < head->nxt->val)
			max = head->nxt->val;
		head = head->nxt;
		if (head == backup)
			break ;
	}
	return (max);
}
