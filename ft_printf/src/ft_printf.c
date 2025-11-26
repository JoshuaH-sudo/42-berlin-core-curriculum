/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 19:55:24 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdarg.h>

void	write_char_and_count(char c, int *total_printed)
{
	ft_putchar_fd(c, 1);
	(*total_printed)++;
}

int	process_format( const char *ptr, va_list *list, int *total_printed)
{
	while (*ptr)
	{
		if (*ptr == '%')
		{
			if (is_valid_specifier(*(ptr + 1)))
			{
				ptr++;
				handle_argument(ptr, list, total_printed);
			}
			else if (*(ptr + 1) == '\0')
				return (-1);
			else
			{
				write_char_and_count(*ptr, total_printed);
			}
			ptr++;
		}
		else
		{
			write_char_and_count(*ptr, total_printed);
			ptr++;
		}
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	const char	*ptr = format;
	va_list		list;
	int			total_printed;
	int			result;

	total_printed = 0;
	va_start(list, format);
	if (!format)
		return (-1);
	result = process_format(ptr, &list, &total_printed);
	if (result == -1)
	{
		va_end(list);
		return (-1);
	}
	va_end(list);
	return (total_printed);
}
