/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:44:13 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:05:56 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	clear_lst(t_stack *stack_a)
{
	t_stack	*tmp;

	if (stack_a == NULL)
		return ;
	stack_a->prv->nxt = NULL;
	while (stack_a)
	{
		tmp = stack_a->nxt;
		free(stack_a);
		stack_a = tmp;
	}
}

void	reverse_stack_a(t_stack **a, t_stack **b, int len)
{
	int		cnt;

	if (len == 2)
		do_op("sa", a, b);
	else if (len == 3)
	{
		do_op("sa", a, b);
		do_op("rra", a, b);
	}
	else
	{
		cnt = 0;
		while (cnt < len - 1)
		{
			do_op("pb", a, b);
			++cnt;
		}
		while (cnt > 0)
		{
			do_op("pa", a, b);
			do_op("ra", a, b);
			--cnt;
		}
	}
}

bool	push_node(t_stack **stack_dst, t_stack *node_to_add)
{
	if (*stack_dst != NULL)
	{
		(*stack_dst)->prv->nxt = node_to_add;
		node_to_add->prv = (*stack_dst)->prv;
		(*stack_dst)->prv = node_to_add;
		node_to_add->nxt = *stack_dst;
	}
	*stack_dst = node_to_add;
	return (true);
}

t_stack	*pop_node(t_stack **stack_src)
{
	t_stack	*node_to_subtract;

	node_to_subtract = *stack_src;
	if (*stack_src == (*stack_src)->nxt)
		*stack_src = NULL;
	else
	{
		(*stack_src)->prv->nxt = (*stack_src)->nxt;
		(*stack_src)->nxt->prv = (*stack_src)->prv;
		*stack_src = (*stack_src)->nxt;
		node_to_subtract->prv = node_to_subtract;
		node_to_subtract->nxt = node_to_subtract;
	}
	return (node_to_subtract);
}

int	get_stack_size(t_stack *stack)
{
	int	size;
	int	last_val;

	if (stack == NULL)
		return (0);
	size = 1;
	last_val = stack->prv->val;
	while (1)
	{
		stack = stack->nxt;
		++size;
		if (stack->val == last_val)
			break ;
	}
	return (size);
}
