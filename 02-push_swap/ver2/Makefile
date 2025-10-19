# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 11:22:40 by sshin             #+#    #+#              #
#    Updated: 2021/08/27 13:17:32 by sshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BNAME	=	checker
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
# CFLAGS	+=	-g -fsanitize=address
AR		=	ar
ARFLAGS	=	-rcs
RM		=	rm -rf

# LIBRARY ARCHIVE
LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIB			=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# HEADERS
INCS_DIR	=	./incs/

# SOURCES
SRCS	=	./srcs/a_to_b.c \
			./srcs/atoi_with_int_check.c \
			./srcs/b_to_a.c \
			./srcs/do_op.c \
			./srcs/parsing.c \
			./srcs/main.c \
			./srcs/set_pvt.c \
			./srcs/sort_by_len.c \
			./srcs/utils_arithmetic.c \
			./srcs/utils_stack.c

# OBJECTS
OBJS	= $(SRCS:.c=.o)

# BONUS SOURCES
BSRCS	=	./bsrcs/c_do_op.c \
			./bsrcs/c_init_stack.c \
			./bsrcs/main.c \
			./srcs/a_to_b.c \
			./srcs/atoi_with_int_check.c \
			./srcs/b_to_a.c \
			./srcs/do_op.c \
			./srcs/parsing.c \
			./srcs/set_pvt.c \
			./srcs/sort_by_len.c \
			./srcs/utils_arithmetic.c \
			./srcs/utils_stack.c

# BONUS OBJECTS
BOBJS	=	$(BSRCS:.c=.o)

# COLOR FLAGS
FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

ifdef FLAG_BONUS
	TARGET = $(BNAME)
else
	TARGET = $(NAME)
endif

all : $(LIB_NAME) $(TARGET)

bonus :
	@make FLAG_BONUS=1 all

$(LIB_NAME) :
	@make -C $(LIB_DIR)
	@printf "${FG_GREEN}Libft make all succeeded!\n${NO_COLOR}"

$(NAME) : $(SRCS) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${FG_GREEN}Projcet make all succeeded!\n${NO_COLOR}"

$(BNAME) : $(BSRCS) $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${FG_GREEN}Project make bonus succeeded!\n${NO_COLOR}"

clean :
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJS) $(BOBJS)
	@printf "${FG_YELLOW}Project make clean succeeded!\n${NO_COLOR}"

fclean : clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(BNAME)
	@printf "${FG_YELLOW}Project make fclean succeeded!\n${NO_COLOR}"

re : fclean all

.PHONY : all clean fclean re bonus
