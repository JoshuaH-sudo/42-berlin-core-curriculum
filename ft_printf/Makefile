# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/26 15:59:43 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = src/ft_printf.c src/handle_char.c src/handle_hex.c \
		src/handle_nbr.c src/handle_str.c src/printf_utils.c
LIBFT = ./libft
OUT_FILES = $(FILES:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

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