/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:00:39 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 15:15:32 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Using ascii table charcter codes to get "printable" charcters
int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
	{
		return (0);
	}
	return (1);
}

/*
#include <stdio.h>
int	main(void)
{
	// ASCII printable characters (character code 32-127)
	// Prints SP
	//char	letter = '\x20';
	// Prints unprintable charcters
	char	letter = '\x1F';

	int result = ft_isascii(letter);

	printf("letter: %c\nresults: %d\n", letter, result);
}
*/
