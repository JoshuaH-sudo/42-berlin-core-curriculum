/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:23:19 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 18:05:23 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void	convert_hex(int fd, unsigned int n, char *hex_digits,
		int *total_printed)
{
	unsigned int	mod;
	char			letter;

	if (n != 0)
	{
		mod = n % 16;
		n = n / 16;
		convert_hex(fd, n, hex_digits, total_printed);
		letter = hex_digits[mod];
		ft_putchar_fd(letter, fd);
		(*total_printed)++;
	}
}

void	handle_hex(va_list *list, int *total_printed, int uppercase)
{
	unsigned int	n;
	char			*hex_digits;

	n = va_arg(*list, unsigned int);
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		(*total_printed)++;
		return ;
	}
	convert_hex(1, n, hex_digits, total_printed);
}
