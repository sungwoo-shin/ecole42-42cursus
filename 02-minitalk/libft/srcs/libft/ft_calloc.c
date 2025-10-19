/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:57:25 by sshin             #+#    #+#             */
/*   Updated: 2021/05/10 17:13:06 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*ret;

	if (!(ret = (void *)malloc(size * cnt)))
		return (NULL);
	ft_bzero(ret, cnt * size);
	return (ret);
}
