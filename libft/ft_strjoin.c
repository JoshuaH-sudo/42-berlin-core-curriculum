/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:01:13 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 12:02:50 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	join(char *dest, char *src, size_t start)
{
	size_t	i;
	size_t	len;

	i = start;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[i + start] = src[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	join(joined_str, s1, 0);
	join(joined_str, s1, len2);
	joined_str[len1 + len2] = '\0';
	return (joined_str);
}
