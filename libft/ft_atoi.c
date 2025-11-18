/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:39:29 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/28 19:08:20 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_number(char str)
{
	if (str < '0' || str > '9')
		return (0);
	else
		return (1);
}

static int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}

static int	calculate(char *str, int minus_count, int *index, int *result)
{
	int	nbr;

	nbr = 0;
	while (is_number(str[*index]))
	{
		nbr = (str[*index] - '0');
		if (minus_count % 2 != 0)
			nbr = 0 - nbr;
		*result += nbr;
		if (!is_number(str[*index + 1]))
			break ;
		*result *= 10;
		*index = *index + 1;
	}
	return (*result);
}

int	ft_atoi(char *str)
{
	int	minus_count;
	int	index;
	int	result;

	index = 0;
	result = 0;
	minus_count = 0;
	while (is_space(str[index]) || str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus_count++;
		index++;
	}
	calculate(str, minus_count, &index, &result);
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	printf("result (0): %d\n", ft_atoi("0"));
	printf("result (0): %d\n", ft_atoi("      ------a2147483648"));
	printf("result (2147483647): %d\n", ft_atoi("2147483647"));
	printf("result (-2147483648): %d\n", ft_atoi("---2147483648"));
	printf("result (0): %d\n", ft_atoi("-0"));
}
*/
