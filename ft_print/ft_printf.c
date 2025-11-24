/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 12:17:54 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

// %c %s %p %d %i %u %x %X %%
int ft_printf(const char *format, ...)
{
    va_list args;
    int total_printed = 0;
    // const char *ptr = format;

    va_start(args, format);

    va_end(args);
    return (total_printed);
}