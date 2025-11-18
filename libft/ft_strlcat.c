/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:50:11 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 15:17:44 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_length(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = get_length(dest);
	src_length = get_length(src);
	index = 0;
	if (dest_length >= size)
		return (src_length + size);
	while (src[index] != '\0' && dest_length + index < size - 1)
	{
		dest[dest_length + index] = src[index];
		index++;
	}
	if (dest_length + index < size)
		dest[dest_length + index] = '\0';
	return (dest_length + src_length);
}
/*
#include <stdio.h>
int	main(void)
{
	char	dest[12] = "hello ";
	char	src[] = "world";
	unsigned int size = 12;

	printf("before:\ndest: %s\nsrc: %s\nsize: %u\n\n", dest, src, size);

	unsigned int result = ft_strlcat(dest, src, size);

	printf("after:\ndest: %s\nsrc: %s\n", dest, src);
	printf("ft_result: %u\n", result);

}
*/
