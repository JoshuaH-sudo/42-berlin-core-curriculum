/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 13:29:25 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	handle_char(va_list *list, int *total_printed)
{
	char	c;

	c = (char)va_arg(*list, int);
	ft_putchar_fd(c, 1);
	(*total_printed)++;
}

void	handle_string(va_list *list, int *total_printed)
{
	const char	*null_str = "(null)";
	char		*str;

	str = va_arg(*list, char *);
	if (*str)
	{
		ft_putstr_fd(str, 1);
		(*total_printed) += ft_strlen(str);
	}
	else
	{
		ft_putstr_fd((char *)null_str, 1);
		(*total_printed) += ft_strlen(null_str);
	}
}

// %c %s %p %d %i %u %x %X %%
int	ft_printf(const char *format, ...)
{
	const char *ptr = format;
	va_list list;
	int total_printed = 0;

	va_start(list, format);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
				handle_char(&list, &total_printed);
			else if (*ptr == 's')
				handle_string(&list, &total_printed);
			else if (*ptr == '%')
			{
				ft_putchar_fd('%', 1);
				total_printed++;
			}
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			total_printed++;
		}
		ptr++;
	}
	va_end(list);
	return (total_printed);
}