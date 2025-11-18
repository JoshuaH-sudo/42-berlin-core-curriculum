/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:00:39 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 15:15:57 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Using ascii table charcter codes to get "printable" charcters
int ft_isprint(int c)
{
	if (c < 32 || c > 126)
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
	// Prints SP DEL
	//char	letter = '\x20';
	// Prints unprintable charcters
	char	letter = '\x80';

	int result = ft_isprint(letter);

	printf("letter: %s\nresults: %d\n", letter, result);
}
*/
