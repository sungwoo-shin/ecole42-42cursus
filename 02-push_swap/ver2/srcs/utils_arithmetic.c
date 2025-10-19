/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:57:28 by sshin             #+#    #+#             */
/*   Updated: 2021/07/26 17:15:42 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
	t_stack	*cur;
	int		min_val;

	cur = head->nxt;
	min_val = head->val;
	while (1)
	{
		if (cur == head)
			break ;
		if (min_val > cur->val)
			min_val = cur->val;
		cur = cur->nxt;
	}
	return (min_val);
}

int	get_max_val(t_stack *head)
{
	t_stack	*cur;
	int		max_val;

	cur = head->nxt;
	max_val = head->val;
	while (1)
	{
		if (cur == head)
			break ;
		if (max_val < cur->val)
			max_val = cur->val;
		cur = cur->nxt;
	}
	return (max_val);
}

int	get_stack_len(t_stack *head)
{
	int	stack_len;
	int	last_val;

	if (head == NULL)
		return (0);
	stack_len = 1;
	last_val = head->prv->val;
	while (1)
	{
		head = head->nxt;
		++stack_len;
		if (head->val == last_val)
			break ;
	}
	return (stack_len);
}
