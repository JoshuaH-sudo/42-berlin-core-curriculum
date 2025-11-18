/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:44:11 by jhoban            #+#    #+#             */
/*   Updated: 2025/10/21 18:43:47 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *s1 = "hello";
	char *s2 = "helao";
	int	n = 4;
	int result = ft_strncmp(s1, s2, n);
	printf("result: %d\n", result);

	// Test with real function.
	int result2 = strncmp(s1, s2, n);
	printf("result2: %d\n", result2);
}
*/