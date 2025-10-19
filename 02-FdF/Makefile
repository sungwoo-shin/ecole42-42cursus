# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 13:39:23 by sshin             #+#    #+#              #
#    Updated: 2021/08/17 20:26:29 by sshin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# CFLAGS	+=	-g -fsanitize=address
AR		= ar
ARFLAGS	= -rcs
RM		= rm
RMFLAGS	= -rf

# LIBRARY ARCHIVE
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) \
			-framework OpenGL -framework AppKit

# HEADERS
HEADERS_LIST = fdf.h\
			key_macos.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

# SOURCES
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = main.c \
			color.c \
			draw.c \
			init.c \
			key.c \
			mouse.c \
			project.c \
			utils.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLOR FLAGS
CLR_BLACK   = \033[0;30m
CLR_RED		= \033[0;31m
CLR_GREEN	= \033[0;32m
CLR_LBLUE   = \033[0;94m
CLR_YELLOW  = \033[0;33m
CLR_MAGENTA = \033[0;35m
CLR_RESET	= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(CLR_GREEN)objects were created$(CLR_RESET)"
	@echo "$(NAME): $(CLR_GREEN)$(NAME) was created$(CLR_RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(CLR_GREEN)$(OBJECTS_DIRECTORY) was created$(CLR_RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CLR_GREEN).$(CLR_RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(CLR_YELLOW)Creating $(LIBFT)...$(CLR_RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(CLR_YELLOW)Creating $(MINILIBX)...$(CLR_RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@$(RM) $(RMFLAGS) $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(CLR_RED)$(OBJECTS_DIRECTORY) was deleted$(CLR_RESET)"
	@echo "$(NAME): $(CLR_RED)objects were deleted$(CLR_RESET)"

fclean: clean
	@$(RM) $(RMFLAGS) $(LIBFT)
	@echo "$(NAME): $(CLR_RED)$(LIBFT) was deleted$(CLR_RESET)"
	@$(RM) $(RMFLAGS) $(MINILIBX)
	@echo "$(NAME): $(CLR_RED)$(MINILIBX) was deleted$(CLR_RESET)"
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "$(NAME): $(CLR_RED)$(NAME) was deleted$(CLR_RESET)"

re: fclean all

.PHONY: all clean fclean re
