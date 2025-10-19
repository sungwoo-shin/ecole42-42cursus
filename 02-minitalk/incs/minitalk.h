/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:41:59 by hyeonski          #+#    #+#             */
/*   Updated: 2021/08/30 12:59:59 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define PID_MAX 99998

# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"

typedef struct s_msg
{
	pid_t		pid_client;
	int			cnt_bit;
	char		buf;
	t_list		*lst;
}				t_msg;

void	terminate(void);
bool	get_jth_bit(char buf, int j);

#endif
