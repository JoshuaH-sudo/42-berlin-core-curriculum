# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 13:03:12 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c
OUT_FILES = $(FILES:.c=.o)

all:
	cc -Wall -Wextra -Werror -c $(FILES) -I ./libft/

$(NAME): all
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OUT_FILES)

clean:
	make -C ./libft clean
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean $(NAME)

test: $(NAME)
	cc -o test test.c $(NAME)
	./test

.PHONY: $(NAME) all clean fclean re
.SILENT: