/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:05 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/25 19:06:36 by jhoban           ###   ########.fr       */
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

static char	**clean_up(char **result, size_t item)
{
	size_t	i;

	i = 0;
	while (i < item)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**assign_strings(char **result, char const *s, char c)
{
	size_t	index;
	size_t	item;
	size_t	start;

	index = 0;
	item = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			start = index;
			while (s[index] && s[index] != c)
				index++;
			result[item] = ft_substr(s, start, index - start);
			if (!result[item])
				return (clean_up(result, item));
			item++;
		}
		else
			index++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;

	count = count_substrings(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = assign_strings(result, s, c);
	if (!result)
		return (NULL);
	result[count] = NULL;
	return (result);
}
