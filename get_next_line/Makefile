# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 18:21:24 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
BUFFER_SIZE = 42
FILES = get_next_line.c get_next_line_utils.c
OUT_FILES = $(FILES:.c=.o)

all: $(NAME)
	
$(NAME): $(OUT_FILES)
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -c $(FILES)
	ar rcs $(NAME) $(OUT_FILES)

clean:
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

test-mac: re
	cc -o test test.c $(NAME)
	./test

test: re
	cc -o test test.c $(NAME) -lbsd
	./test

.PHONY: all clean fclean re