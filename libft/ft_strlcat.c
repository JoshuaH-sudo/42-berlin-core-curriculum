/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:50:11 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/18 19:19:23 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
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
