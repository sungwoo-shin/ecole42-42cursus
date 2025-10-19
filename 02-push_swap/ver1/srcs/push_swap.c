/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:52:40 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:04:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	int		len;
	t_stack	*a;
	t_stack	*b;

	len = ac - 1;
	if (len < 1)
		return (0);
	create_lst(&a, &b, av);
	check_dup(a);
	if (len > 1 && is_dscnd(a, len))
		reverse_stack_a(&a, &b, len);
	else if (len > 2 && !is_ascnd(a, len))
		sort_by_len(&a, &b, len);
	// print_lst(a);
	clear_lst(a);
	return (0);
}

// void	print_lst(t_stack *a)
// {
// 	t_stack *tail;

// 	tail = a->prv;
// 	while (1)
// 	{
// 		printf("%d ", a->val);
// 		a = a->nxt;
// 		if (a == tail)
// 		{
// 			printf("%d ", a->val);
// 			break ;
// 		}
// 	}
// }

void	create_lst(t_stack **a, t_stack **b, char **av)
{
	int		ifroma;
	t_stack	*new_node;

	*a = NULL;
	*b = NULL;
	while (*(++av))
	{
		ifroma = atoi_with_int_check(*av, *a);
		new_node = create_new_node(ifroma, *a);
		append_new_node(a, new_node);
	}
}

t_stack	*create_new_node(int ifroma, t_stack *a)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack) * 1);
	if (new_node == NULL)
		handle_error(a);
	new_node->val = ifroma;
	new_node->prv = new_node;
	new_node->nxt = new_node;
	return (new_node);
}

void	append_new_node(t_stack **a, t_stack *new_node)
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

void	check_dup(t_stack *a)
{
	t_stack	*tail;
	t_stack	*tmp;

	tail = a->prv;
	tmp = a->nxt;
	while (1)
	{
		if (a == tail)
			break ;
		while (1)
		{
			if (tmp == tail->nxt)
				break ;
			if (a->val == tmp->val)
				handle_error(a);
			tmp = tmp->nxt;
		}
		a = a->nxt;
		tmp = a->nxt;
	}
}
