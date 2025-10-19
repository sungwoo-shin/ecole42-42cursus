/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 22:00:31 by sshin             #+#    #+#             */
/*   Updated: 2021/05/11 22:03:31 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t limit)
{
	size_t	i;

	if (!*find)
		return ((char *)str);
	if (!ft_strlen(str) || limit < ft_strlen(find))
		return (NULL);
	i = 0;
	while (i + ft_strlen(find) <= limit && str[i])
	{
		if (str[i] == find[0] && !ft_memcmp(&str[i], &find[0], ft_strlen(find)))
			return ((char *)str + i);
		++i;
	}
	return (NULL);
}
