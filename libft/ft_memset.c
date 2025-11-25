/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:03:10 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/25 15:55:52 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	str = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		str[index] = (unsigned char)c;
		index++;
	}
	return (str);
}
