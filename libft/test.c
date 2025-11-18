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

void  run_test(char *name, int (*fn)(void))
{
    printf("Running test: %s\n", name);
    if (fn())
        printf("Test %s passed!\n", name);
    else
        printf("Test %s failed!\n", name);
}

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

int test_ft_memcpy(void)
{
    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];
    ft_memcpy(dest1, src, sizeof(src));
    memcpy(dest2, src, sizeof(src));
    if (memcmp(dest1, dest2, sizeof(src)) == 0)
        return 1; // Test passed
    return 0; // Test failed
}

int main(void)
{
    run_test("ft_bzero", test_ft_bzero);
    run_test("ft_memcpy", test_ft_memcpy);
    return 0;
}