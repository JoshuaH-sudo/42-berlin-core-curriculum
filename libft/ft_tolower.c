/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:20:21 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/19 10:01:36 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] + 32;
		index++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	word[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
	printf("word: %s\n", word);
	printf("result: %s\n", ft_strlowcase(word))
}
*/
