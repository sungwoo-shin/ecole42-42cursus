/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_init_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:16:42 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:44:39 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	append_new_node(t_stack **a, t_stack *new_node)
{
	if (*a == NULL)
		*a = new_node;
	else
	{
		(*a)->prv->nxt = new_node;
		new_node->prv = (*a)->prv;
		(*a)->prv = new_node;
		new_node->nxt = *a;
	}
}

static t_stack	*create_new_node(int ifroma)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack) * 1);
	if (new_node == NULL)
		terminate();
	new_node->val = ifroma;
	new_node->prv = new_node;
	new_node->nxt = new_node;
	return (new_node);
}

void	c_init_stack(char **av, t_stack **a, t_stack **b)
{
	int		ifroma;
	t_stack	*new_node;

	*a = NULL;
	*b = NULL;
	while (*av)
	{
		ifroma = atoi_with_int_check(*av);
		new_node = create_new_node(ifroma);
		append_new_node(a, new_node);
		++av;
	}
}

void	c_check_dup(t_stack *a)
{
	t_stack	*tail;
	t_stack	*cur;

	tail = a->prv;
	cur = a->nxt;
	while (1)
	{
		if (a == tail)
			break ;
		while (1)
		{
			if (cur == tail->nxt)
				break ;
			if (a->val == cur->val)
				terminate();
			cur = cur->nxt;
		}
		a = a->nxt;
		cur = a->nxt;
	}
}
