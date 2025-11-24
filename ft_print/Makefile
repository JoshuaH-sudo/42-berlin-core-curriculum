# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 12:19:10 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c
OUT_FILES = $(FILES:.c=.o) ./libft/libft.a

.PHONY: $(NAME) all clean fclean ar norm
all:
	make -C ./libft libft.a
	cc -Wall -Wextra -Werror -c $(FILES)

$(NAME): all
	ar rcs $(NAME) $(OUT_FILES)

clean:
	make -C ./libft clean
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean $(NAME)

