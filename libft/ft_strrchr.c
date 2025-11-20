/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:53:17 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 10:34:44 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/**
 * Gets the last occurrence of a character in a string.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ptr_to_char;

	index = ft_strlen(s);
	// We go backwards through the string to get the last occurrence
	while (index >= 0)
	{
		if (s[index] == (char)c)
		{
			ptr_to_char = (char *)&s[index];
			return (ptr_to_char);
		}
		index--;
	}
	return (NULL);
}
