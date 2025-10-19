/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:00:06 by sshin             #+#    #+#             */
/*   Updated: 2021/07/24 16:11:27 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	rewind_stack_a(t_stack **a, t_stack **b, int cnt_ra)
{
	while (cnt_ra > 0)
	{
		do_op("rra", a, b);
		--cnt_ra;
	}
}

void	b_to_a(t_stack **a, t_stack **b, int cnt)
{
	t_info	info;

	if (break_b_to_a(a, b, cnt))
		return ;
	info.pvt_b = get_pvt(*b, cnt, create_arr(*a, cnt));
	info.cnt_pa = 0;
	info.cnt_rb = 0;
	while (cnt-- > 0)
	{
		if ((*b)->val > info.pvt_b)
		{
			do_op("pa", a, b);
			++(info.cnt_pa);
		}
		else
		{
			do_op("rb", a, b);
			++(info.cnt_rb);
		}
	}
	rewind_stack_b(a, b, info.cnt_rb);
	a_to_b(a, b, info.cnt_pa);
	b_to_a(a, b, info.cnt_rb);
}

bool	break_b_to_a(t_stack **a, t_stack **b, int cnt)
{
	if (cnt == 1)
	{
		do_op("pa", a, b);
		return (true);
	}
	return (false);
}

void	rewind_stack_b(t_stack **a, t_stack **b, int cnt_rb)
{
	while (cnt_rb > 0)
	{
		do_op("rrb", a, b);
		--cnt_rb;
	}
}
