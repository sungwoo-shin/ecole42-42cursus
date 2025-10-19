/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swshin <swshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:57:47 by sshin             #+#    #+#             */
/*   Updated: 2021/06/03 01:16:27 by swshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	int				read_file_ret;
	int				read_size;
	int				idx_to_split;

	if (BUFFER_SIZE < 1 || fd < 0 || OPEN_MAX <= fd || !line )
		return (_ERROR);
	read_file_ret = _GO_TO_ASSIGN_LAST_LINE;
	// Check if line feeds already exist in 'backup[fd]'.
	// Call the function 'read_file', only if there is no line feed in the 'backup[fd]'.
	if ((idx_to_split = get_idx_to_split(backup[fd])) == _LF_NOT_FOUND)
		read_file_ret = read_file(fd, &backup[fd], &read_size, &idx_to_split);
	else
		return (split_line(&backup[fd], line, idx_to_split));
	if (read_file_ret == _ERROR)
		return (_ERROR);
	if (read_file_ret == _LF_FOUND)
		return (split_line(&backup[fd], line, idx_to_split));
	return (assign_last_line(&backup[fd], line, read_size));
}

int		get_idx_to_split(char *backup)
{
	int		idx;

	if (!backup)
		return (_LF_NOT_FOUND);
	idx = 0;
	while (backup[idx])
	{
		if (backup[idx] == '\n')
			return (idx);
		++idx;
	}
	return (_LF_NOT_FOUND);
}

int		read_file(int fd, char **backup, int *read_size, int *idx_to_split)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (buf == NULL)
	// 	return (_ERROR);
	while ((*read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*read_size] = '\0';
		tmp = ft_strjoin(*backup, buf);
		// if (tmp == NULL)
		// {
		// 	free(buf);
		// 	return (_ERROR);
		// }
		free(*backup);
		*backup = ft_strdup(tmp);
		// if (*backup == NULL)
		// {
		// 	free(buf);
		// 	free(tmp);
		// 	return (_ERROR);
		// }
		free(tmp);
		if ((*idx_to_split = get_idx_to_split(*backup)) >= 0)
		{
			free(buf);
			return (_LF_FOUND);
		}
	}
	free(buf);
	// EOF has been reached.
	return (_GO_TO_ASSIGN_LAST_LINE);
}

int		split_line(char **backup, char **line, int idx_to_split)
{
	int		rest_len;
	char	*tmp;

	(*backup)[idx_to_split] = '\0';
	*line = ft_strdup(*backup);
	// if (*line == NULL)
	// {
	// 	free(*backup);
	// 	return (_ERROR);
	// }
	if ((rest_len = ft_strlen(*backup + idx_to_split + 1)) == 0)
	{
		free(*backup);
		*backup = NULL;
	}
	else
	{
		tmp = ft_strdup(*backup + idx_to_split + 1);
		// if (tmp == NULL)
		// {
		// 	free(*backup);
		// 	return (_ERROR);
		// }
		free(*backup);
		*backup = tmp;
	}
	return (_A_LINE);
}

int		assign_last_line(char **backup, char **line, int read_size)
{
	if (read_size < 0)
		return (_ERROR);
	if (*backup)
	{
		*line = *backup;
		*backup = NULL;
		return (_EOF);
	}
	*line = ft_strdup("");
	// if (*line == NULL)
	// {
	// 	free(*backup);
	// 	return (_ERROR);
	// }
	return (_EOF);
}
