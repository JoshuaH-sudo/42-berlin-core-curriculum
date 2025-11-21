/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:03:10 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/21 17:06:06 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			index;

	s = str;
	index = 0;
	while (index < n)
	{
		s[index] = c;
		index++;
	}
	return (str);
}
