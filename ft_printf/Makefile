# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 16:32:39 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c
OUT_FILES = $(FILES:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OUT_FILES)
	cc $(CFLAGS) -c $(FILES)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OUT_FILES)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean $(NAME)

test: $(NAME)
	cc -o test test.c $(NAME)
	./test

.PHONY: $(NAME) all clean fclean re