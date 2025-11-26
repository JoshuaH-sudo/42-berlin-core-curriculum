# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 21:17:16 by jhoban            #+#    #+#              #
#    Updated: 2025/11/26 16:43:07 by jhoban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = src
FILES = src/ft_printf.c src/handle_char.c src/handle_hex.c \
		src/handle_nbr.c src/handle_str.c src/printf_utils.c
LIBFT = libft/libft.a
LIBFT_DIR = libft
OUT_FILES = $(FILES:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OUT_FILES)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OUT_FILES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OUT_FILES)
	rm -f test

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	cc -o test test.c $(NAME)
	./test

.PHONY: $(NAME) all clean fclean re