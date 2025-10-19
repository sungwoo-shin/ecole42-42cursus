/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:48:26 by sshin             #+#    #+#             */
/*   Updated: 2021/09/22 19:21:08 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = 0;
		++s;
		--n;
	}
}

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*ret;

	ret = (void *)malloc(size * cnt);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, cnt * size);
	return (ret);
}

void	mdealloc(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
