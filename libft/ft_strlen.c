/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:55:42 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/19 16:59:20 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

/*
#include <stdio.h>
int	main(void)
{
	char word[] = "hello world";
	int result = ft_strlen(word);

	printf("word: %s\nlength: %d", word, result);
}
*/
