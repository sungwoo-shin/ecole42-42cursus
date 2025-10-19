/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_do_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 00:49:15 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:44:28 by sshin            ###   ########.fr       */
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

void	c_do_op(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa") && op_s(*a))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "sb") && op_s(*b))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "ss") && op_s(*a) && op_s(*b))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "pa") && push_node(a, pop_node(b)))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "pb") && push_node(b, pop_node(a)))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "ra") && op_r(a))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rb") && op_r(b))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rr") && op_r(a) && op_r(b))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rra") && op_rr(a))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rrb") && op_rr(b))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(str, "rrr") && op_rr(a) && op_rr(b))
		ft_putstr_fd("", STDOUT_FILENO);
	else
		terminate();
}
