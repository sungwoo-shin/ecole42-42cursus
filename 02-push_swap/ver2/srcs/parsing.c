/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:18:48 by sshin             #+#    #+#             */
/*   Updated: 2021/08/27 13:19:51 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_len_with_null_check(char **av)
{
	int		len;
	char	*ptr_backup;

	len = 0;
	while (*av)
	{
		if (**av == '\0')
			terminate();
		ptr_backup = *av;
		while (**av)
		{
			while (**av && **av == ' ')
				++(*av);
			if (**av && **av != ' ')
				++len;
			while (**av && **av != ' ')
				++(*av);
		}
		*av = ptr_backup;
		++av;
	}
	return (len);
}

static int	get_cnt_char(char ***av)
{
	int	cnt_char;

	cnt_char = 0;
	while (***av && ***av != ' ')
	{
		++cnt_char;
		++(**av);
	}
	return (cnt_char);
}

static char	*get_parsed_av_ith(char ***av, int cnt_char)
{
	char	*parsed_av_ith;

	parsed_av_ith = malloc(sizeof(char) * (cnt_char + 1));
	if (parsed_av_ith == NULL)
		terminate();
	parsed_av_ith[cnt_char] = '\0';
	while (cnt_char > 0)
	{
		--(**av);
		--cnt_char;
		parsed_av_ith[cnt_char] = ***av;
	}
	while (***av && ***av != ' ')
		++(**av);
	return (parsed_av_ith);
}

void	split_av(char ***av, int len)
{
	char	**parsed_av;
	int		i;
	int		cnt_char;

	parsed_av = (char **)malloc(sizeof(char *) * (len + 1));
	if (parsed_av == NULL)
		terminate();
	i = 0;
	while (**av)
	{
		while (***av)
		{
			while (***av && ***av == ' ')
				++(**av);
			cnt_char = get_cnt_char(av);
			if (cnt_char == 0)
				break ;
			parsed_av[i] = get_parsed_av_ith(av, cnt_char);
			++i;
		}
		++(*av);
	}
	parsed_av[len] = NULL;
	*av = parsed_av;
}

void	clear_av(char ***av)
{
	int	i;

	i = 0;
	while ((*av)[i])
	{
		free((*av)[i]);
		(*av)[i] = NULL;
		++i;
	}
	free(*av);
	*av = NULL;
}
