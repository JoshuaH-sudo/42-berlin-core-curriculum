/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:37:29 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 10:57:26 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloced_memory;
	size_t	amount;

	amount = count * size;
	if (count == 0 || size == 0)
		amount = 1;
	alloced_memory = malloc(amount);
	if (alloced_memory == NULL)
		return (NULL);
	ft_memset(alloced_memory, 0, amount);
	return (alloced_memory);
}
