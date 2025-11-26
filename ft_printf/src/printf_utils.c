/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:19:38 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 16:03:15 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdarg.h>
#include <string.h>

char	*int_to_hex(unsigned long num)
{
	static char	buffer[17];
	char		*ptr;
	const char	*digits = "0123456789abcdef";

	ptr = &buffer[16];
	*ptr = '\0';
	if (num == 0)
	{
		*(--ptr) = '0';
		return (ptr);
	}
	while (num > 0)
	{
		*(--ptr) = digits[num % 16];
		num /= 16;
	}
	return (ptr);
}

void	handle_pointer(va_list *list, int *total_printed)
{
	void	*ptr;
	char	*hex_str;

	ptr = va_arg(*list, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		(*total_printed) += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		(*total_printed) += 2;
		hex_str = int_to_hex((unsigned long)ptr);
		ft_putstr_fd(hex_str, 1);
		(*total_printed) += ft_strlen(hex_str);
	}
}

void	handle_percent(int *total_printed)
{
	ft_putchar_fd('%', 1);
	(*total_printed)++;
}

void	handle_argument(const char *ptr, va_list *list, int *total_printed)
{
	if (*ptr == 'c')
		handle_char(list, total_printed);
	else if (*ptr == 's')
		handle_string(list, total_printed);
	else if (*ptr == 'p')
		handle_pointer(list, total_printed);
	else if (*ptr == 'd' || *ptr == 'i')
		handle_number(list, total_printed);
	else if (*ptr == 'u')
		handle_unsigned(list, total_printed);
	else if (*ptr == 'x')
		handle_hex(list, total_printed, 0);
	else if (*ptr == 'X')
		handle_hex(list, total_printed, 1);
	else if (*ptr == '%')
		handle_percent(total_printed);
}
