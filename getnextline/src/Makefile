# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 11:22:48 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
BUFFER_SIZE = 42
FILES = get_next_line.c get_next_line_utils.c
OUT_FILES = $(FILES:.c=.o)

.PHONY: all clean fclean ar norm test test-mac
all:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -c $(FILES)
$(NAME): all
	ar rcs $(NAME) $(OUT_FILES)

clean:
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette

test-mac: re
	cc -o test test.c $(NAME)
	./test

test: re
	cc -o test test.c $(NAME) -lbsd
	./test