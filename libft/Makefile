# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 18:16:39 by pemeyer           #+#    #+#              #
#    Updated: 2018/09/18 12:51:54 by pemeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I. -c
RM			= rm -f
FILES		= ft_memset.c\
			  ft_bzero.c\
			  ft_memcpy.c\
			  ft_memccpy.c\
			  ft_memmove.c\
			  ft_memchr.c\
			  ft_memcmp.c\
			  ft_strlen.c\
			  ft_strdup.c\
			  ft_strndup.c\
			  ft_strcpy.c\
			  ft_strncpy.c\
			  ft_strcat.c\
			  ft_strncat.c\
			  ft_strlcat.c\
			  ft_strchr.c\
			  ft_strrchr.c\
			  ft_strstr.c\
			  ft_strnstr.c\
			  ft_strcmp.c\
			  ft_strncmp.c\
			  ft_atoi.c\
			  ft_isalpha.c\
			  ft_isdigit.c\
			  ft_isalnum.c\
			  ft_isascii.c\
			  ft_isprint.c\
			  ft_itoa_base.c\
			  ft_toupper.c\
			  ft_tolower.c\
			 ft_putchar.c\
			 ft_putnchar.c\
			ft_putstr.c\
		   ft_putendl.c\
			ft_putchar_fd.c\
	 ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbrmax_fd.c\
	ft_putnbr_fd.c\
	ft_strtok.c\
	ft_nbrlen.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_strmap.c\
ft_strjoin.c\
ft_strmapi.c\
ft_striteri.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_strtrim.c\
ft_strsplit.c\
ft_itoa.c\
ft_memcpy_rev.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_lst_len.c\
ft_lst_append.c\
ft_lst_free.c\
ft_printhex.c\
ft_printf.c\
handle_c.c\
handle_d.c\
handle_gap.c\
handle_o.c\
handle_other.c\
handle_p.c\
handle_s.c\
handle_u.c\
handle_wchar.c\
handle_ws.c\
handle_x.c\
init.c\
parse_handlers.c\
print_printf.c\
checks.c\
get_next_line.c\
ft_realloc.c

OBJ			= $(FILES:%.c=%.o)

.phony: all clean fclean re

$(NAME):
	@gcc $(CFLAGS) $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader
