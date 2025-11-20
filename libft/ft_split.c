/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:05 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 10:34:42 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	count_substrings(char const *s, char c)
{
	int		i;
	size_t	count;
	int		in_substring;

	i = 0;
	count = 0;
	in_substring = 0;
	while (s[i])
	{
		if (s[i] != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_substring = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char **result;
	size_t count;

	count = count_substrings(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[count] = NULL;
	size_t index = 0;
	size_t item = 0;
	size_t start = 0;
	size_t end = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			start = index;
			while (s[index] && s[index] != c)
				index++;
			end = index;
			result[item] = ft_substr(s, start, end - start);
			item++;
		}
		else
		{
			index++;
		}
	}

	return (result);
}