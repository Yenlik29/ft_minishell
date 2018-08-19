# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 13:45:37 by ybokina           #+#    #+#              #
#    Updated: 2018/08/18 10:17:57 by ybokina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

FLAGS := -Wall -Wextra -Werror

SOURCES := main.c ft_env1.c ft_display.c ft_line.c ft_symbols.c ft_actions.c ft_error1.c ft_error2.c ft_core.c ft_free.c ft_build_in.c ft_cd.c ft_path.c ft_execution.c ft_cd2.c ft_error3.c ft_cd3.c ft_setenv.c ft_env2.c ft_unsetenv.c ft_error4.c

OBJ := $(SOURCES:.c=.o)

HEADER := ft_minishell.h

LIBFT := $(LIBFT_DIR)libft.a

LIBFT_DIR := libft/

HEADER_FLAGS := -I. -I $(LIBFT_DIR)

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(SOURCES) -lft -L $(LIBFT_DIR)

$(OBJ_DIR)%.o: %c. ft_minishell.h
	@$(CC) -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
