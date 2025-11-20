/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:06:05 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 11:47:58 by jhoban           ###   ########.fr       */
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

char	**assign_strings(char const *s, char c, int count)
{
	size_t	index;
	size_t	item;
	size_t	start;
	size_t	end;
	char	**result;

	index = 0;
	item = 0;
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
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;

	count = count_substrings(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = assign_strings(s, c, count);
	result[count] = NULL;
	return (result);
}
