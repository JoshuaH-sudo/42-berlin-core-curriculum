/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:19:41 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 18:05:20 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void	convert_decimal(int nb, int fd, int *total_printed)
{
	int		mod;
	char	letter;

	if (nb != 0)
	{
		mod = nb % 10;
		nb = nb / 10;
		convert_decimal(nb, fd, total_printed);
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
		(*total_printed)++;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		(*total_printed)++;
		return ;
	}
	convert_decimal(n, 1, total_printed);
}

void	convert_unsigned(unsigned int n, int fd, int *total_printed)
{
	unsigned int	mod;
	char			letter;

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

void	handle_unsigned(va_list *list, int *total_printed)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		(*total_printed)++;
		return ;
	}
	convert_unsigned(n, 1, total_printed);
}
