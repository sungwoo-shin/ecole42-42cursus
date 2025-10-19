/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:06:26 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:11:12 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	do_op(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa") && op_s(*a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && op_s(*b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ss") && op_s(*a) && op_s(*b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "pa") && push_node(a, pop_node(b)))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && push_node(b, pop_node(a)))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "ra") && op_r(a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && op_r(b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rr") && op_r(a) && op_r(b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rra") && op_rr(a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && op_rr(b))
		write(1, "rrb\n", 4);
	else if (!ft_strcmp(str, "rrr") && op_rr(a) && op_rr(b))
		write(1, "rrr\n", 4);
}

bool	op_s(t_stack *head)
{
	int	tmp;

	tmp = head->val;
	head->val = head->nxt->val;
	head->nxt->val = tmp;
	return (true);
}

bool	op_r(t_stack **head)
{
	*head = (*head)->nxt;
	return (true);
}

bool	op_rr(t_stack **head)
{
	*head = (*head)->prv;
	return (true);
}
