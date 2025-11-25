/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:50:11 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 10:34:43 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dest_length;
	size_t	src_length;

	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	index = 0;
	if (dest_length >= dstsize)
		return (src_length + dstsize);
	while (src[index] != '\0' && dest_length + index < dstsize - 1)
	{
		dst[dest_length + index] = src[index];
		index++;
	}
	if (dest_length + index < dstsize)
		dst[dest_length + index] = '\0';
	return (dest_length + src_length);
}
