/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:44:13 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:37:40 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	terminate(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

void	clear_stack(t_stack *head)
{
	t_stack	*tmp;

	if (head == NULL)
		return ;
	head->prv->nxt = NULL;
	while (head)
	{
		tmp = head->nxt;
		free(head);
		head = tmp;
	}
}

void	reverse_stack_a(t_stack **a, t_stack **b, int len)
{
	int		cnt_pb;

	if (len == 2)
		do_op("sa", a, b);
	else if (len == 3)
	{
		do_op("sa", a, b);
		do_op("rra", a, b);
	}
	else
	{
		cnt_pb = 0;
		while (cnt_pb < len - 1)
		{
			do_op("pb", a, b);
			++cnt_pb;
		}
		while (cnt_pb > 0)
		{
			do_op("pa", a, b);
			do_op("ra", a, b);
			--cnt_pb;
		}
	}
}

t_stack	*pop_node(t_stack **head_src)
{
	t_stack	*node_to_subtract;

	node_to_subtract = *head_src;
	if (*head_src == (*head_src)->nxt)
		*head_src = NULL;
	else
	{
		(*head_src)->prv->nxt = (*head_src)->nxt;
		(*head_src)->nxt->prv = (*head_src)->prv;
		*head_src = (*head_src)->nxt;
		node_to_subtract->prv = node_to_subtract;
		node_to_subtract->nxt = node_to_subtract;
	}
	return (node_to_subtract);
}

bool	push_node(t_stack **head_dst, t_stack *node_to_add)
{
	if (*head_dst != NULL)
	{
		(*head_dst)->prv->nxt = node_to_add;
		node_to_add->prv = (*head_dst)->prv;
		(*head_dst)->prv = node_to_add;
		node_to_add->nxt = *head_dst;
	}
	*head_dst = node_to_add;
	return (true);
}
