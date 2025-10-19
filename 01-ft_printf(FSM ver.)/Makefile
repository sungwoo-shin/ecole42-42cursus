# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 23:03:28 by snam              #+#    #+#              #
#    Updated: 2021/10/11 01:02:55 by sshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	ft_printf.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f

INCS			=	./incs

SRCS_DIR	=	./srcs/
SRCS_LST 	=	ft_printf.c			\
				ft_printf_utils.c	\
				print_letter.c		\
				print_nbr.c			\
				process.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
