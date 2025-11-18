/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:43:39 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/18 20:33:09 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;
    size_t i;

    d = dest;
    s = src;
    // if the destination is not in the source region, we can copy forwards like a normal memcpy
    if (d < s)
    {
        return ft_memcpy(dest, src, n);
    }
    else
    {
        // work backwards to avoid overwriting source data
        i = n;
        while (i > 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }
    }
    return (dest);
}