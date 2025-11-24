# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 11:23:03 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OUT_FILES = $(FILES:.c=.o)

.PHONY: all clean fclean ar norm test test-mac
$(NAME): all
	ar rcs $(NAME) $(OUT_FILES)
all:
	cc -Wall -Wextra -Werror -c $(FILES)

clean:
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

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