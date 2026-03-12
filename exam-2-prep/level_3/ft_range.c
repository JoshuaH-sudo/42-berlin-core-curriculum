/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:41:45 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 17:56:55 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = abs(start - end) + 1;
    int *result = (int *)malloc(len * sizeof(int));
    while (i < len)
    {
        if (start <= end)
            result[i++] = start++;
		else if (start >= end)
			result[i++] = start--;
    }
    i = 0;
    while (i < len)
    {
        printf("%d,", result[i++]);
    }
    return (result);
}

int main()
{
    ft_range(0,3);
    printf("\n");
    ft_range(-1,2);
    printf("\n");
    ft_range(0,0);
    printf("\n");
    ft_range(0,-3);
    printf("\n");
}

// Examples:
// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.