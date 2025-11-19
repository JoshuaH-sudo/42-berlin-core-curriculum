/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:37:29 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 14:42:01 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
  void *alloced_memory;
  alloced_memory = malloc(count * size);
  if (alloced_memory == NULL)
    return (NULL);
  ft_memset(alloced_memory, 0, count * size);
  return (alloced_memory);
}
