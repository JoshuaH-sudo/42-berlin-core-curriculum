/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 12:46:21 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

// %c %s %p %d %i %u %x %X %%
int ft_printf(const char *format, ...)
{
    const char *ptr = format;
    va_list args;
    int total_printed = 0;

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                ft_putchar_fd(va_arg(args, int), 1);
                ptr++;
            }
        }
        ft_putchar_fd(*ptr, 1);
        ptr++;
    }

    va_end(args);
    return (total_printed);
}