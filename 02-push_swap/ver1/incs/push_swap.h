/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:28:31 by swshin            #+#    #+#             */
/*   Updated: 2021/07/24 16:10:57 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> // <-
# include "../libft/incs/libft.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*prv;
	struct s_stack	*nxt;
}				t_stack;

typedef struct s_info
{
	int	pvt_a; //int	pvt_less;
	int	pvt_b; //int	pvt_greater;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_pb;
}				t_info;

void	print_lst(t_stack *a);

/* main.c
** =============================================================================
*/
void	create_lst(t_stack **a, t_stack **b, char **av);
t_stack	*create_new_node(int ifroma, t_stack *a);
void	append_new_node(t_stack **a, t_stack *new_node);
void	check_dup(t_stack *a);

/* ft_atoi_with_int_check.c
** =============================================================================
*/
int		atoi_with_int_check(const char *str, t_stack *a);
bool	is_plusminus(char c);
bool	is_nbr(char c);
void	apply_sign(int sign, long long *ret);
void	check_int(long long ret, t_stack *a);

/* sort_by_len.c
** =============================================================================
*/
void	sort_by_len(t_stack **a, t_stack **b, int len);
void	sort_3(t_stack **a, t_stack **b);
void	sort_4_or_5(t_stack **a, t_stack **b);
void	sort_minmax(t_stack **a, t_stack **b, int min_val);

/* a_to_b.c
** =============================================================================
*/
void	a_to_b(t_stack **a, t_stack **b, int cnt);
bool	break_a_to_b(t_stack **a, t_stack **b, int cnt);
int		*create_arr(t_stack *a, int cnt);
int		get_pvt(t_stack *head, int cnt, int *arr);
int		free_arr_then_get_ret(int *arr, int ret);

/* b_to_a.c
** =============================================================================
*/
void	rewind_stack_a(t_stack **a, t_stack **b, int cnt_ra);
void	b_to_a(t_stack **a, t_stack **b, int cnt);
bool	break_b_to_a(t_stack **a, t_stack **b, int cnt);
void	rewind_stack_b(t_stack **a, t_stack **b, int cnt_rb);

/* push_swap_utils.c
** =============================================================================
*/
void	handle_error(t_stack *a);
bool	is_dscnd(t_stack *stack, int len);
bool	is_ascnd(t_stack *stack, int len);
int		get_min_val(t_stack *stack);
int		get_max_val(t_stack *stack);

/* stack_utils.c
** =============================================================================
*/
void	clear_lst(t_stack *a);
void	reverse_stack_a(t_stack **a, t_stack **b, int len);
bool	push_node(t_stack **stack_dst, t_stack *node_to_add);
t_stack	*pop_node(t_stack **stack);
int		get_stack_size(t_stack *stack);

/* do_op.c
** =============================================================================
*/
void	do_op(char *str, t_stack **a, t_stack **b);
bool	op_s(t_stack *head);
bool	op_r(t_stack **head);
bool	op_rr(t_stack **head);

#endif
