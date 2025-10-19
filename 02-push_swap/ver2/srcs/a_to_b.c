/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:48:38 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:35:31 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	conquer_a(t_stack **a, t_stack **b, int cnt)
{
	if (cnt == 2 || cnt == 3)
	{
		if ((*a)->val > (*a)->nxt->val)
			do_op("sa", a, b);
		if (cnt == 3 && !is_ascnd(*a, cnt))
		{
			do_op("ra", a, b);
			do_op("sa", a, b);
			do_op("rra", a, b);
			if ((*a)->val > (*a)->nxt->val)
				do_op("sa", a, b);
		}
	}
	else if (cnt == 4)
		sort_4(a, b);
	else if (cnt == 5)
		sort_5(a, b);
}

static void	divide_a(t_stack **a, t_stack **b, int cnt, t_param *param)
{
	while (cnt > 0)
	{
		if ((*a)->val <= param->pvt_less)
		{
			do_op("pb", a, b);
			++(param->cnt_pb);
		}
		else if ((*a)->val > param->pvt_greater)
		{
			do_op("ra", a, b);
			++(param->cnt_ra);
		}
		else
		{
			do_op("pb", a, b);
			++(param->cnt_pb);
			do_op("rb", a, b);
			++(param->cnt_rb);
		}
		--cnt;
	}
}

void	a_to_b(t_stack **a, t_stack **b, int cnt)
{
	t_param	param;

	if (cnt <= 5)
	{
		if (!is_ascnd(*a, cnt))
			conquer_a(a, b, cnt);
		return ;
	}
	param = (t_param){0, };
	set_pvt(*a, cnt, 'a', &param);
	divide_a(a, b, cnt, &param);
	rewind_stack(a, b, param.cnt_rb);
	a_to_b(a, b, param.cnt_ra);
	b_to_a(a, b, param.cnt_rb);
	b_to_a(a, b, param.cnt_pb - param.cnt_rb);
}
