/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:24 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 21:38:32 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


int test_ft_bzero(void)
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    ft_bzero(str1, sizeof(char) * 5);
    bzero(str2, sizeof(char) * 5);
    if (memcmp(str1, str2, sizeof(str1)) == 0)
        return 1; // Test passed
    return 0; // Test failed
}

int main(void)
{
    if (test_ft_bzero())
        printf("ft_bzero test passed!\n");
    else
        printf("ft_bzero test failed!\n");
    return 0;
}