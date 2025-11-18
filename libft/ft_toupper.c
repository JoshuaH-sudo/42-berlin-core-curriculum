/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:20:21 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/18 13:09:08 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] = str[index] - 32;
		index++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	word[] = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
	printf("word: %s\n", word);
	ft_strupcase(word);
	printf("word: %s\n", word);
}
*/
