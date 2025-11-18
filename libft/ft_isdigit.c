/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:43:13 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 15:15:46 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c)
{
	if ((c < '0' || c > '9'))
	{
		return (0);
	}
	return (c);
}

/*
#include <stdio.h>
int	main(void)
{
	char	number = '9';

	int result = ft_isdigit(number);

	printf("number: %c\nresults: %d\n", number, result);
}
*/
