/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:24 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/18 16:23:13 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void  run_test(char *name, int (*fn)(void))
{
    if (fn())
        printf("Test %s OK!\n", name);
    else
        printf("Test %s KO!\n", name);
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

int test_ft_memchr(void)
{
    char str[] = "Hello, World!";
    char *res1 = ft_memchr(str, 'W', sizeof(str));
    char *res2 = memchr(str, 'W', sizeof(str));
    if (res1 == res2)
        return 1; // Test passed
    return 0; // Test failed
}

int test_ft_isalpha(void)
{
    int ok = 1;
    ok &= (ft_isalpha('A') == isalpha('A'));
    ok &= (ft_isalpha('z') == isalpha('z'));
    ok &= (ft_isalpha('1') == isalpha('1'));
    ok &= (ft_isalpha('@') == isalpha('@'));
    return ok;
}

int test_ft_isascii(void)
{
    printf("return %d\n", isascii(-1));
    int ok = 1;
    ok &= (ft_isascii(0) == isascii(0));
    ok &= (ft_isascii(127) == isascii(127));
    ok &= (ft_isascii(128) == isascii(128));
    ok &= (ft_isascii(-1) == isascii(-1));
    ok &= (ft_isascii(256) == isascii(256));
    return ok;
}

int test_ft_isdigit(void)
{
    int ok = 1;
    ok &= (ft_isdigit('0') == isdigit('0'));
    ok &= (ft_isdigit('9') == isdigit('9'));
    ok &= (ft_isdigit('a') == isdigit('a'));
    ok &= (ft_isdigit('/') == isdigit('/'));
    return ok;
}

int test_ft_isprint(void)
{
    int ok = 1;
    ok &= (ft_isprint(32) == isprint(32));
    ok &= (ft_isprint(127) == isprint(127));
    ok &= (ft_isprint(31) == isprint(31));
    ok &= (ft_isprint(128) == isprint(128));
    return ok;
}

int main(void)
{
    // run_test("ft_bzero", test_ft_bzero);
    // run_test("ft_memcpy", test_ft_memcpy);
    // run_test("ft_memchr", test_ft_memchr);
    // run_test("ft_isalpha", test_ft_isalpha);
    run_test("ft_isascii", test_ft_isascii);
    // run_test("ft_isdigit", test_ft_isdigit);
    // run_test("ft_isprint", test_ft_isprint);
    return 0;
}