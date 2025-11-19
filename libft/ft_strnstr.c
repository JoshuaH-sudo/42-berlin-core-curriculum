/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:59:29 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 14:06:47 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t str_index;
	size_t search_index;
	char *ptr_to_substring;

	str_index = 0;
	search_index = 0;
	ptr_to_substring = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[str_index] != '\0')
	{
		while (haystack[str_index + search_index] == needle[search_index] && (str_index + search_index) < len)
		{
			if (needle[search_index + 1] == '\0')
			{
				ptr_to_substring = (char *)&haystack[str_index];
				return (ptr_to_substring);
			}
			search_index++;
		}
		search_index = 0;
		str_index++;
	}
	return (ptr_to_substring);
}
