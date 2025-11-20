# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/20 12:21:58 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

.PHONY: all clean fclean ar norm test test-mac
all:
	cc -Wall -Wextra -Werror -c *.c

clean:
	rm -f *.o
	rm -f test

fclean: clean
	rm -f $(NAME)

ar: all
	ar rcs $(NAME) *.o

norm:
	norminette

test-mac: all ar
	cc -o test ../test.c $(NAME)
	echo "Running tests:"
	./test | tee test_output.txt
	grep "KO!" test_output.txt && echo "Some tests failed." || echo "All tests passed."

test: all ar
	cc -o test ../test.c $(NAME) -lbsd
	echo "Running tests:"
	./test | tee test_output.txt
	grep "KO!" test_output.txt && echo "Some tests failed." || echo "All tests passed."