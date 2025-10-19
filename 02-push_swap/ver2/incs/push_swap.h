/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:28:31 by swshin            #+#    #+#             */
/*   Updated: 2021/08/24 13:08:44 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*prv;
	struct s_stack	*nxt;
}				t_stack;

typedef struct s_param
{
	int		idx_pvt_less;
	int		idx_pvt_greater;
	int		pvt_less;
	int		pvt_greater;
	int		cnt_ra;
	int		cnt_rb;
	int		cnt_pa;
	int		cnt_pb;
}				t_param;

/* parsing.c
** =============================================================================
*/
int		get_len_with_null_check(char **av);
void	clear_av(char ***av);
void	split_av(char ***av, int len);

/* atoi_with_int_check.c
** =============================================================================
*/
int		atoi_with_int_check(const char *str);

/* sort_by_len.c
** =============================================================================
*/
void	sort_by_len(t_stack **a, t_stack **b, int len);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);

/* do_op.c
** =============================================================================
*/
void	do_op(char *str, t_stack **a, t_stack **b);
void	rewind_stack(t_stack **a, t_stack **b, int cnt);

/* a_to_b.c
** =============================================================================
*/
void	a_to_b(t_stack **a, t_stack **b, int cnt);

/* set_pvt.c
** =============================================================================
*/
void	set_pvt(t_stack *a, int cnt, char flag_stack, t_param *param);

/* b_to_a.c
** =============================================================================
*/
void	b_to_a(t_stack **a, t_stack **b, int cnt);

/* utils_stack.c
** =============================================================================
*/
void	terminate(void);
void	clear_stack(t_stack *a);
void	reverse_stack_a(t_stack **a, t_stack **b, int len);
t_stack	*pop_node(t_stack **head_src);
bool	push_node(t_stack **head_dst, t_stack *node_to_add);

/* utils_arithmetic.c
** =============================================================================
*/
bool	is_dscnd(t_stack *head, int len);
bool	is_ascnd(t_stack *head, int len);
int		get_min_val(t_stack *head);
int		get_max_val(t_stack *head);
int		get_stack_len(t_stack *head);

/* /bsrcs
** =============================================================================
*/
void	c_init_stack(char **av, t_stack **a, t_stack **b);
void	c_check_dup(t_stack *a);
void	c_do_op(char *str, t_stack **a, t_stack **b);

#endif
