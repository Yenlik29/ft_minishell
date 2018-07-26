# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 13:45:37 by ybokina           #+#    #+#              #
#    Updated: 2018/06/29 17:08:31 by ybokina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

FLAGS := -Wall -Wextra -Werror

SOURCES := main.c ft_env1.c ft_display.c ft_line.c ft_symbols.c ft_actions.c

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
