/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:06:26 by sshin             #+#    #+#             */
/*   Updated: 2021/08/05 17:45:47 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static bool	op_s(t_stack *head)
{
	int	tmp;

	tmp = head->val;
	head->val = head->nxt->val;
	head->nxt->val = tmp;
	return (true);
}

static bool	op_r(t_stack **head)
{
	*head = (*head)->nxt;
	return (true);
}

static bool	op_rr(t_stack **head)
{
	*head = (*head)->prv;
	return (true);
}

void	do_op(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa") && op_s(*a))
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "sb") && op_s(*b))
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "ss") && op_s(*a) && op_s(*b))
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "pa") && push_node(a, pop_node(b)))
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "pb") && push_node(b, pop_node(a)))
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "ra") && op_r(a))
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rb") && op_r(b))
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rr") && op_r(a) && op_r(b))
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rra") && op_rr(a))
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rrb") && op_rr(b))
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rrr") && op_rr(a) && op_rr(b))
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

void	rewind_stack(t_stack **a, t_stack **b, int cnt)
{
	while (cnt > 0)
	{
		do_op("rrr", a, b);
		--cnt;
	}
}
