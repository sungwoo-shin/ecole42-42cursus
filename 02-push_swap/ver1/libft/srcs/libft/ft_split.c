/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:40:49 by sshin             #+#    #+#             */
/*   Updated: 2021/05/20 14:12:58 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt_w(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static char		**ft_free_ret(char **ret, int i)
{
	while (--i >= 0 && ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
	}
	free(ret);
	ret = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	*break_point;
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s || !(ret = (char **)malloc(sizeof(char *) * (ft_cnt_w(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			break_point = (char *)s;
			while (*s && *s != c)
				++s;
			len = s - break_point + 1;
			if (!(ret[i] = (char *)malloc(len)))
				return (ft_free_ret(ret, i));
			ft_strlcpy(ret[i++], break_point, len);
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
