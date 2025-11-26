/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 15:58:17 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	const char	*ptr = format;
	va_list		list;
	int			total_printed;

	total_printed = 0;
	va_start(list, format);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			handle_argument(ptr, &list, &total_printed);
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
