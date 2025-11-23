# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/23 17:39:06 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
BUFFER_SIZE = 42

.PHONY: all clean fclean ar norm test test-mac
$(NAME): all
	ar rcs $(NAME) *.o

all:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -c *.c

clean:
	rm -f *.o
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette

test-mac: re
	cc -o test test.c $(NAME)
	echo "Running tests:"
	./test | tee test_output.txt
	grep "KO!" test_output.txt && echo "Some tests failed." || echo "All tests passed."

test: re
	cc -o test test.c $(NAME) -lbsd
	echo "Running tests:"
	./test | tee test_output.txt
	grep "KO!" test_output.txt && echo "Some tests failed." || echo "All tests passed."