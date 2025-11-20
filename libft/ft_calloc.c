/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:37:29 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 10:34:41 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloced_memory;

	// Handle edge case: if count or size is 0, allocate minimal memory
	if (count == 0 || size == 0)
		alloced_memory = malloc(1);
	else
		alloced_memory = malloc(count * size);
	if (alloced_memory == NULL)
		return (NULL);
	// Zero the allocated memory
	if (count == 0 || size == 0)
		ft_memset(alloced_memory, 0, 1);
	else
		ft_memset(alloced_memory, 0, count * size);
	return (alloced_memory);
}
