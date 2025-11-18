# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/18 16:50:06 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

.PHONY: all clean fclean ar test
all:
	cc -Wall -Wextra -Werror -c *.c

clean:
	rm -f *.o
	rm -f test

fclean: clean
	rm -f $(NAME)

ar: all
	ar rcs $(NAME) *.o

test: all ar
	cc -lbsd -o test test.c $(NAME)
	echo "Running tests:"
	./test | tee test_output.txt
	grep "KO!" test_output.txt && echo "Some tests failed." || echo "All tests passed."