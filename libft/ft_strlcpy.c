/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:19:08 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/18 13:45:19 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	if (size > 0)
	{
		while (src[index] != '\0' && index < size - 1)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (index);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*src = "hello, world!";
	char	dest[10]; // should get: "Hello, wo"

	printf("src: %s\ndest_size:%lu", src, sizeof(dest));

	ft_strlcpy(dest, src, sizeof(dest));
	printf("\n\n");

	printf("dest: %s", dest);
}
*/
