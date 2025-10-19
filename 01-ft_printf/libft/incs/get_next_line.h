/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 10:51:12 by sshin             #+#    #+#             */
/*   Updated: 2021/06/25 10:56:01 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 12800
# endif

# define LF_NOT_FOUND -1
# define LF_FOUND 1

/*
** ========== get_next_line.c ==========
*/
int		get_next_line(int fd, char **line);
int		read_file(int fd, char **backup_fd, int *idx_to_split);
int		get_idx_to_split(char *backup_fd);
int		split_line(char **backup_fd, char **line, int cut_idx);
int		assign_last_line(char **backup_fd, char **line);

/*
** ========== get_next_line_utils.c ==========
*/
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
