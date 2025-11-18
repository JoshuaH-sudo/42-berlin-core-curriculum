/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:54:05 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/21 17:48:29 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: handle 'n' param
char	*ft_strnstr(char *str, char *to_find)
{
	int		str_index;
	int		search_index;
	char	*ptr_to_substring;

	str_index = 0;
	search_index = 0;
	ptr_to_substring = 0;
	if (!to_find[0])
		return (str);
	while (str[str_index] != '\0')
	{
		while (str[str_index + search_index] == to_find[search_index])
		{
			if (to_find[search_index + 1] == '\0')
			{
				ptr_to_substring = &str[str_index];
				return (ptr_to_substring);
			}
			search_index++;
		}
		search_index = 0;
		str_index++;
	}
	return (ptr_to_substring);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "hello world world start";
	char	to_find[] = "";

	printf("str: %s\nto_find:%s\n\n", str, to_find);

	char *ft_ptr_to_str = ft_strstr(str, to_find);
	char *ptr_to_str = strstr(str, to_find);

	//check we get the same output:
	// Real function
	printf("real strstr() value address: %p\n",ptr_to_str);
	// Our function
	printf("our ft_strstr() value: %p\n", ft_ptr_to_str);
}
*/
