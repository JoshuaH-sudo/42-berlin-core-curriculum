/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:11:16 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 10:57:17 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static char	*convert(int nb, char *str, int start)
{
	int		mod;

	if (nb != 0)
	{
		mod = nb % 10;
		nb = nb / 10;
		convert(nb, str, start - 1);
		if (mod < 0)
			mod = 0 - mod;
		str[start] = (char)(mod + '0');
	}
	return (str);
}

static int	count_digits(int n)
{
	int		count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	check_negative(int n)
{
	int		is_negative;

	if (n < 0)
		is_negative = 1;
	else
		is_negative = 0;
	return (is_negative);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		is_negative;

	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	is_negative = check_negative(n);
	digits = count_digits(n) + is_negative;
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (is_negative)
		str[0] = '-';
	str = convert(n, str, digits - 1 - is_negative);
	str[digits] = '\0';
	return (str);
}
