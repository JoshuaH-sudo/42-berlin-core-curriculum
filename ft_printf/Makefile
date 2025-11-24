# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/24 18:04:58 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c handle_char.c handle_hex.c \
		handle_nbr.c handle_str.c printf_utils.c
LIBFT = ./libft
OUT_FILES = $(FILES:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OUT_FILES)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OUT_FILES)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean $(NAME)

test: $(NAME)
	cc -o test test.c $(NAME)
	./test

.PHONY: $(NAME) all clean fclean re