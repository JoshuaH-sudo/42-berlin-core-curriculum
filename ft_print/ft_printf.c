/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 15:36:08 by jhoban           ###   ########.fr       */
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
	ft_putstr_fd("0x", 1);
	(*total_printed) += 2;
	if (ptr == NULL)
	{
		ft_putstr_fd("0", 1);
		(*total_printed) += 1;
	}
	else
	{
		hex_str = int_to_hex((unsigned long)ptr);
		ft_putstr_fd(hex_str, 1);
		(*total_printed) += ft_strlen(hex_str);
	}
}

static void	convert(int nb, int fd, int *total_printed)
{
	int		mod;
	char	letter;

	if (nb != 0)
	{
		mod = nb % 10;
		nb = nb / 10;
		convert(nb, fd, total_printed);
		if (mod < 0)
			mod = 0 - mod;
		letter = mod + '0';
		ft_putchar_fd(letter, fd);
		(*total_printed)++;
	}
}

void	handle_number(va_list *list, int *total_printed)
{
	int	n;

	n = va_arg(*list, int);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	convert(n, 1, total_printed);
}

static void   convert_unsigned(unsigned int n, int fd, int *total_printed)
{
    unsigned int    mod;
    char            letter;

    if (n != 0)
    {
        mod = n % 10;
        n = n / 10;
        convert_unsigned(n, fd, total_printed);
        letter = mod + '0';
        ft_putchar_fd(letter, fd);
        (*total_printed)++;
    }
}

void    handle_unsigned(va_list *list, int *total_printed)
{
    unsigned int    n;

    n = va_arg(*list, unsigned int);
    if (n == 0)
    {
        ft_putchar_fd('0', 1);
        (*total_printed)++;
        return ;
    }
    convert_unsigned(n, 1, total_printed);
}

static char *convert_hex(int fd, unsigned int n, char *hex_digits, int *total_printed) 
{
    unsigned int    mod;
    char            letter;

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

void    handle_hex(va_list *list, int *total_printed, int uppercase)
{
    unsigned int    n;
    char    *hex_digits;

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

void	handle_percent(int *total_printed)
{
	ft_putchar_fd('%', 1);
	(*total_printed)++;
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
			else if (*ptr == 'p')
				handle_pointer(&list, &total_printed);
            else if (*ptr == 'd' || *ptr == 'i')
                handle_number(&list, &total_printed);
            else if (*ptr == 'u')
                handle_unsigned(&list, &total_printed);
            else if (*ptr == 'x')
                handle_hex(&list, &total_printed, 0);
            else if (*ptr == 'X')
                handle_hex(&list, &total_printed, 1);
			else if (*ptr == '%')
				handle_percent(&total_printed);
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