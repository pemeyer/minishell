# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pemeyer <pemeyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 08:57:52 by pemeyer           #+#    #+#              #
#    Updated: 2018/09/18 12:03:00 by pemeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c\
	  builtin_log.c\
	  builtins1.c\


LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "Creating $(NAME) ..."
	@make -C libft/
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)
clean:
	@echo "Cleaning libft ..."
	@rm -rf libft/*o
	@rm -rf libft/libft.a
fclean: clean
	@echo "Cleaning $(NAME) ..."
	@rm -rf $(NAME)
re: fclean all
