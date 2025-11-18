/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:43:13 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 15:15:24 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
	{
		return (0);
	}
	return (c);
}

/*
#include <stdio.h>
int	main(void)
{
	char	letter = 'h';

	int result = ft_isalpha(letter);

	printf("letter: %c\nresults: %d\n", letter, result);
}
*/
