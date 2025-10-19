/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:57:47 by sshin             #+#    #+#             */
/*   Updated: 2021/06/25 10:57:38 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	int 		idx_to_split;
	int 		read_file_ret;

	if (BUFFER_SIZE < 1 || fd < 0 || OPEN_MAX <= fd || line == NULL \
			|| read(fd, "", 0) == -1)
		return (-1);
	if ((idx_to_split = get_idx_to_split(backup[fd])) == LF_NOT_FOUND)
		read_file_ret = read_file(fd, &backup[fd], &idx_to_split);
	else
		return (split_line(&backup[fd], line, idx_to_split));
	if (read_file_ret == -1)
		return (-1);
	else if (read_file_ret == LF_FOUND)
		return (split_line(&backup[fd], line, idx_to_split));
	else
		return (assign_last_line(&backup[fd], line));
}

int	get_idx_to_split(char *backup_fd)
{
	int idx;

	if (backup_fd == NULL)
		return (LF_NOT_FOUND);
	idx = 0;
	while (backup_fd[idx])
	{
		if (backup_fd[idx] == '\n')
			return (idx);
		++idx;
	}
	return (LF_NOT_FOUND);
}

int	read_file(int fd, char **backup_fd, int *idx_to_split)
{
	char 	*buf;
	char 	*tmp;
	int		read_size;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!(tmp = ft_strjoin(*backup_fd, buf)))
		{
			free(buf);
			return (-1);
		}
		free(*backup_fd);
		*backup_fd = tmp;
		if ((*idx_to_split = get_idx_to_split(*backup_fd)) != LF_NOT_FOUND)
		{
			free(buf);
			return (LF_FOUND);
		}
	}
	// EOF has been reached.
	free(buf);
	return (0);
}

int	split_line(char **backup_fd, char **line, int idx_to_split)
{
	char *tmp;

	(*backup_fd)[idx_to_split] = '\0';
	if (!(*line = ft_strdup(*backup_fd)))
	{
		free(*backup_fd);
		return (-1);
	}
	tmp = ft_strdup(*backup_fd + idx_to_split + 1);
	free(*backup_fd);
	*backup_fd = tmp;
	return (1);
}

int	assign_last_line(char **backup_fd, char **line)
{
	if (*backup_fd)
	{
		*line = *backup_fd;
		*backup_fd = NULL;
		return (0);
	}
	if (!(*line = ft_strdup("")))
	{
		free(*backup_fd);
		return (-1);
	}
	return (0);
}
