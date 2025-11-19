/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:19:08 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 17:25:11 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t index;

	index = 0;
	if (dstsize > 0)
	{
		while (src[index] != '\0' && index < dstsize - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}