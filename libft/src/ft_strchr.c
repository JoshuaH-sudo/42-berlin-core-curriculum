/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:52:03 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/21 17:07:24 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ptr_to_char;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
		{
			ptr_to_char = (char *)&s[index];
			return (ptr_to_char);
		}
		index++;
	}
	if (s[index] == (char)c)
	{
		ptr_to_char = (char *)&s[index];
		return (ptr_to_char);
	}
	return (NULL);
}
