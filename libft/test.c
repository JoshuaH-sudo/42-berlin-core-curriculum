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
    printf("--------------------------------\n");
    printf("Running test: %s\n", name);
    printf("--------------------------------\n");
    if (fn())
        printf("Test %s OK!\n", name);
    else
        printf("Test %s KO!\n", name);
    printf("--------------------------------\n\n");
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
    printf("checked A: %d\n", ok);
    ok &= (ft_isalpha('z') == isalpha('z'));
    printf("checked z: %d\n", ok);
    ok &= (ft_isalpha('1') == isalpha('1'));
    printf("checked 1: %d\n", ok);
    ok &= (ft_isalpha('@') == isalpha('@'));
    printf("checked @: %d\n", ok);
    return ok;
}

int test_ft_isascii(void)
{
    printf("return %d\n", isascii(128));
    printf("return ft %d\n", ft_isascii(128));
    int ok = 1;
    ok &= ((ft_isascii(0) == 1) == (isascii(0) == 1));
    printf("checked 0: %d\n", ok);
    ok &= ((ft_isascii(127) == 1) == (isascii(127) == 1));
    printf("checked 127: %d\n", ok);
    ok &= ((ft_isascii(128) == 0) == (isascii(128) == 0));
    printf("checked 128: %d\n", ok);
    ok &= ((ft_isascii(-1) == 0) == (isascii(-1) == 0));
    printf("checked -1: %d\n", ok);
    ok &= ((ft_isascii(256) == 0) == (isascii(256) == 0));
    printf("checked 256: %d\n", ok);
    return ok;
}

int test_ft_isdigit(void)
{
    int ok = 1;
    ok &= (ft_isdigit('0') == isdigit('0'));
    printf("checked '0': %d\n", ok);
    ok &= (ft_isdigit('9') == isdigit('9'));
    printf("checked '9': %d\n", ok);
    ok &= (ft_isdigit('a') == isdigit('a'));
    printf("checked 'a': %d\n", ok);
    ok &= (ft_isdigit('/') == isdigit('/'));
    printf("checked '/': %d\n", ok);
    return ok;
}

int test_ft_isprint(void)
{
    int ok = 1;
    ok &= (ft_isprint(32) == isprint(32));
    printf("checked 32: %d\n", ok);
    ok &= (ft_isprint(126) == isprint(126));
    printf("checked 126: %d\n", ok);
    ok &= (ft_isprint(127) == isprint(127));
    printf("checked 127: %d\n", ok);
    ok &= (ft_isprint(31) == isprint(31));
    printf("checked 31: %d\n", ok);
    ok &= (ft_isprint(128) == isprint(128));
    printf("checked 128: %d\n", ok);
    return ok;
}

int main(void)
{
    run_test("ft_bzero", test_ft_bzero);
    run_test("ft_memcpy", test_ft_memcpy);
    run_test("ft_memchr", test_ft_memchr);
    run_test("ft_isalpha", test_ft_isalpha);
    run_test("ft_isascii", test_ft_isascii);
    run_test("ft_isdigit", test_ft_isdigit);
    run_test("ft_isprint", test_ft_isprint);
    return 0;
}