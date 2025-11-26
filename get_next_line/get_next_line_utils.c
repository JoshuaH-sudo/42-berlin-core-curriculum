/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 18:03:58 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_joinstr(char *dest, char *src, size_t dest_len, size_t src_len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)malloc((dest_len + src_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		new_str[i] = dest[i];
		i++;
	}
	j = 0;
	while (j < src_len)
	{
		new_str[i + j] = src[j];
		j++;
	}
	new_str[dest_len + src_len] = '\0';
	return (new_str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}