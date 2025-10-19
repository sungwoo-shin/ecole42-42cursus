/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:00:06 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:35:54 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	conquer_b(t_stack **a, t_stack **b, int cnt)
{
	if (cnt == 2 || cnt == 3)
	{
		if ((*b)->val < (*b)->nxt->val)
			do_op("sb", a, b);
		if (cnt == 3)
		{
			if (!is_dscnd(*b, cnt))
			{
				do_op("rb", a, b);
				do_op("sb", a, b);
				do_op("rrb", a, b);
				if ((*b)->val < (*b)->nxt->val)
					do_op("sb", a, b);
			}
			do_op("pa", a, b);
		}
		do_op("pa", a, b);
	}
	do_op("pa", a, b);
}

static void	divide_b(t_stack **a, t_stack **b, int cnt, t_param *param)
{
	while (cnt > 0)
	{
		if ((*b)->val >= param->pvt_greater)
		{
			do_op("pa", a, b);
			++(param->cnt_pa);
		}
		else if ((*b)->val < param->pvt_less)
		{
			do_op("rb", a, b);
			++(param->cnt_rb);
		}
		else
		{
			do_op("pa", a, b);
			++(param->cnt_pa);
			do_op("ra", a, b);
			++(param->cnt_ra);
		}
		--cnt;
	}
}

void	b_to_a(t_stack **a, t_stack **b, int cnt)
{
	t_param	param;

	if (cnt <= 3)
	{
		conquer_b(a, b, cnt);
		return ;
	}
	param = (t_param){0, };
	set_pvt(*b, cnt, 'b', &param);
	divide_b(a, b, cnt, &param);
	a_to_b(a, b, param.cnt_pa - param.cnt_ra);
	rewind_stack(a, b, param.cnt_ra);
	a_to_b(a, b, param.cnt_ra);
	b_to_a(a, b, param.cnt_rb);
}
