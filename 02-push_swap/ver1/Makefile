# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 11:22:40 by sshin             #+#    #+#              #
#    Updated: 2021/07/24 15:31:01 by sshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g -fsanitize=address
AR		=	ar
ARFLAGS	=	-rcs
RM		=	rm -rf

INCS_DIR	=	./incs/

SRCS_DIR	=	./srcs/
SRCS_LST	= a_to_b.c \
			atoi_with_int_check.c \
			b_to_a.c \
			do_op.c \
			push_swap.c \
			sort_by_len.c \
			utils_arithmetic.c \
			utils_stack.c

LIB_DIR		=	./libft/
LIB_NAME	=	libft.a

SRCS	= $(addprefix $(SRCS_DIR), $(OBJS))
LIBS	= $(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS	= $(SRCS_LST:.c=.o)

#	make -C $(LIB_DIR)
#	$(CC) $(CFLAGS) -c $< -I $(INCS_DIR)
# gcc option
# -c 		: 오브젝트 파일 생성
# -I <dir>	: 참조할 헤더파일의 주소를 추가
# -o		: 실행파일을 만든다.

all : $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(NAME) : $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(SRCS)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
