# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/17 21:39:33 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

.PHONY: all clean fclean ar test
all:
	cc -Wall -Wextra -Werror -c *.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

ar: all
	ar rcs $(NAME) *.o

test: all
	cc -o test test.c $(NAME)
	echo "Running tests:"
	./test