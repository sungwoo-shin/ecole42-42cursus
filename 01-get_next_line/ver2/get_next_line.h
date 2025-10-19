/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:51:12 by sshin             #+#    #+#             */
/*   Updated: 2021/06/13 15:55:00 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define _ERROR -1
# define _EOF 0
# define _A_LINE 1

# define _LF_FOUND -2
# define _LF_NOT_FOUND -3
# define _GO_TO_ASSIGN_LAST_LINE -4

int		get_next_line(int fd, char **line);
int		read_file(int fd, char **backup_fd, int *idx_to_split);
int		get_idx_to_split(char *backup_fd);
int		split_line(char **backup_fd, char **line, int cut_idx);
int		assign_last_line(char **backup_fd, char **line);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
