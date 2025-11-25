/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:39:29 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/21 17:05:28 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}

static int	calculate(const char *str, int minus_count, int *index, int *result)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(str[*index]))
	{
		nbr = (str[*index] - '0');
		if (minus_count % 2 != 0)
			nbr = 0 - nbr;
		*result += nbr;
		if (!ft_isdigit(str[*index + 1]))
			break ;
		*result *= 10;
		*index = *index + 1;
	}
	return (*result);
}

int	ft_atoi(const char *str)
{
	int		minus_count;
	int		index;
	int		result;

	index = 0;
	result = 0;
	minus_count = 0;
	while (is_space(str[index]))
	{
		index++;
	}
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus_count++;
		index++;
	}
	calculate(str, minus_count, &index, &result);
	return (result);
}
