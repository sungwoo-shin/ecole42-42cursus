/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:48:38 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:11:37 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	a_to_b(t_stack **a, t_stack **b, int cnt)
{
	t_info	info;

	if (break_a_to_b(a, b, cnt))
		return ;
	int *arr = create_arr(*a, cnt);
	info.pvt_a = get_pvt(*a, cnt, arr);
	info.cnt_ra = 0;
	info.cnt_pb = 0;
	while (cnt-- > 0)
	{
		if ((*a)->val > info.pvt_a)
		{
			do_op("ra", a, b);
			++(info.cnt_ra);
		}
		else
		{
			do_op("pb", a, b);
			++(info.cnt_pb);
		}
	}
	rewind_stack_a(a, b, info.cnt_ra);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_pb);
}

bool	break_a_to_b(t_stack **a, t_stack **b, int cnt)
{
	if (cnt == 1)
		return (true);
	else if (cnt == 2)
	{
		if (is_dscnd(*a, 2))
			reverse_stack_a(a, b, 2);
		return (true);
	}
	return (false);
}

int	*create_arr(t_stack *a, int cnt)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * cnt);
	if (arr == NULL)
		handle_error(a);
	return (arr);
}

int	get_pvt(t_stack *head, int cnt, int *arr)
{
	int	i;
	int	j;
	int	cnt_greater;

	i = 0;
	while (i < cnt)
	{
		arr[i] = head->val;
		head = head->nxt;
		++i;
	}
	i = -1;
	while (++i < cnt)
	{
		j = -1;
		cnt_greater = 0;
		while (++j < cnt)
		{
			if (arr[i] < arr[j])
				++cnt_greater;
		}
		if (cnt_greater == cnt / 2)
			break ;
	}
	return (free_arr_then_get_ret(arr, arr[i]));
}

int	free_arr_then_get_ret(int *arr, int ret)
{
	free(arr);
	return (ret);
}
