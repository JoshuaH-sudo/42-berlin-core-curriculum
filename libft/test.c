/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:24 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/18 19:17:01 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void run_test(char *name, int (*fn)(void))
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
    return 0;     // Test failed
}

int test_ft_memcpy(void)
{
    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];
    ft_memcpy(dest1, src, sizeof(src));
    memcpy(dest2, src, sizeof(src));
    char str[] = "1234567890";

    // Move the last 5 characters to the beginning
    memcpy(str, str + 5, 5);

    // Add null terminator for printing
    str[5] = '\0';

    printf("str = %s\n", str);
    if (memcmp(dest1, dest2, sizeof(src)) == 0)
        return 1; // Test passed
    return 0;     // Test failed
}

int test_ft_memchr(void)
{
    char str[] = "Hello, World!";
    char *res1 = ft_memchr(str, 'W', sizeof(str));
    char *res2 = memchr(str, 'W', sizeof(str));
    if (res1 == res2)
        return 1; // Test passed
    return 0;     // Test failed
}

int test_ft_isalpha(void)
{
    int ok = 1;
    ok &= (ft_isalpha('A') == 1);
    printf("checked A: %d\n", ok);
    ok &= (ft_isalpha('z') == 1);
    printf("checked z: %d\n", ok);
    ok &= (ft_isalpha('1') == 0);
    printf("checked 1: %d\n", ok);
    ok &= (ft_isalpha('@') == 0);
    printf("checked @: %d\n", ok);
    return ok;
}

int test_ft_isascii(void)
{
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
    ok &= (ft_isdigit('0') == 1);
    printf("checked '0': %d\n", ok);
    ok &= (ft_isdigit('9') == 1);
    printf("checked '9': %d\n", ok);
    ok &= (ft_isdigit('a') == 0);
    printf("checked 'a': %d\n", ok);
    ok &= (ft_isdigit('/') == 0);
    printf("checked '/': %d\n", ok);
    ok &= (ft_isdigit(0) == 0);
    printf("checked 0: %d\n", ok);
    ok &= (ft_isdigit(127) == 0);
    printf("checked 127: %d\n", ok);
    return ok;
}

int test_ft_isprint(void)
{
    int ok = 1;
    ok &= (ft_isprint(32) == 1);
    printf("checked 32: %d\n", ok);
    ok &= (ft_isprint(126) == 1);
    printf("checked 126: %d\n", ok);
    ok &= (ft_isprint(127) == 0);
    printf("checked 127: %d\n", ok);
    ok &= (ft_isprint(31) == 0);
    printf("checked 31: %d\n", ok);
    ok &= (ft_isprint(128) == 0);
    printf("checked 128: %d\n", ok);
    return ok;
}

int test_ft_strlen(void)
{
    int ok = 1;
    ok &= (ft_strlen("") == strlen(""));
    printf("checked empty: %d\n", ok);
    ok &= (ft_strlen("abc") == strlen("abc"));
    printf("checked 'abc': %d\n", ok);
    ok &= (ft_strlen("hello world") == strlen("hello world"));
    printf("checked 'hello world': %d\n", ok);
    ok &= (ft_strlen("a\0hidden") == strlen("a\0hidden"));
    printf("checked 'a\\0hidden': %d\n", ok);
    return ok;
}

int test_ft_strncmp(void)
{
    printf("empty result: %d\n", strncmp("abc", "", 2));
    printf("empty ft_result: %d\n", ft_strncmp("abc", "", 2));

    int ok = 1;
    ok &= (ft_strncmp("abc", "abc", 3) == strncmp("abc", "abc", 3));
    printf("checked equal: %d\n", ok);
    ok &= (ft_strncmp("abc", "abd", 3) == strncmp("abc", "abd", 3));
    printf("checked diff: %d\n", ok);
    ok &= (ft_strncmp("abc", "abc", 0) == strncmp("abc", "abc", 0));
    printf("checked n=0: %d\n", ok);
    // We don't compare to strncmp here because its behavior with empty strings can vary
    ok &= (ft_strncmp("abc", "", 2) == 97);
    printf("checked vs empty: %d\n", ok);
    return ok;
}

// int test_ft_strlcpy(void)
// {
//     #include <bsd/string.h>
//     char src[] = "hello, world!";
//     char dest1[20];
//     char dest2[20];
//     unsigned int ret1 = ft_strlcpy(dest1, src, sizeof(dest1));
//     unsigned int ret2 = strlcpy(dest2, src, sizeof(dest2));
//     int ok = (strcmp(dest1, dest2) == 0) && (ret1 == ret2);
//     printf("checked strlcpy: %d\n", ok);
//     return ok;
// }

// int test_ft_strlcat(void)
// {
//     #include <bsd/string.h>
//     char dest1[20] = "hello ";
//     char dest2[20] = "hello ";
//     char src[] = "world";
//     unsigned int ret1 = ft_strlcat(dest1, src, sizeof(dest1));
//     unsigned int ret2 = strlcat(dest2, src, sizeof(dest2));
//     int ok = (strcmp(dest1, dest2) == 0) && (ret1 == ret2);
//     printf("checked strlcat: %d\n", ok);
//     return ok;
// }

int test_ft_strnstr(void)
{
    char str[] = "hello world world start";
    char to_find[] = "world";
    char *res1 = ft_strnstr(str, to_find);
    char *res2 = strstr(str, to_find);
    int ok = (res1 == res2 || (res1 && res2 && strcmp(res1, res2) == 0));
    printf("checked strnstr: %d\n", ok);
    return ok;
}

int test_ft_tolower(void)
{
    int ok = 1;
    char test1[] = "HELLO WORLD";
    char expected1[] = "hello world";
    char *result1 = ft_tolower(test1);
    ok &= (strcmp(result1, expected1) == 0);
    printf("checked uppercase to lowercase: %d\n", ok);
    
    char test2[] = "hello world";
    char expected2[] = "hello world";
    char *result2 = ft_tolower(test2);
    ok &= (strcmp(result2, expected2) == 0);
    printf("checked already lowercase: %d\n", ok);
    
    char test3[] = "Hello123World!";
    char expected3[] = "hello123world!";
    char *result3 = ft_tolower(test3);
    ok &= (strcmp(result3, expected3) == 0);
    printf("checked mixed case with numbers/symbols: %d\n", ok);
    
    char test4[] = "";
    char expected4[] = "";
    char *result4 = ft_tolower(test4);
    ok &= (strcmp(result4, expected4) == 0);
    printf("checked empty string: %d\n", ok);
    
    return ok;
}

int test_ft_toupper(void)
{
    int ok = 1;
    char test1[] = "hello world";
    char expected1[] = "HELLO WORLD";
    char *result1 = ft_toupper(test1);
    ok &= (strcmp(result1, expected1) == 0);
    printf("checked lowercase to uppercase: %d\n", ok);
    
    char test2[] = "HELLO WORLD";
    char expected2[] = "HELLO WORLD";
    char *result2 = ft_toupper(test2);
    ok &= (strcmp(result2, expected2) == 0);
    printf("checked already uppercase: %d\n", ok);
    
    char test3[] = "Hello123World!";
    char expected3[] = "HELLO123WORLD!";
    char *result3 = ft_toupper(test3);
    ok &= (strcmp(result3, expected3) == 0);
    printf("checked mixed case with numbers/symbols: %d\n", ok);
    
    char test4[] = "";
    char expected4[] = "";
    char *result4 = ft_toupper(test4);
    ok &= (strcmp(result4, expected4) == 0);
    printf("checked empty string: %d\n", ok);
    
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
    run_test("ft_strlen", test_ft_strlen);
    run_test("ft_strncmp", test_ft_strncmp);
    // run_test("ft_strlcpy", test_ft_strlcpy);
    // run_test("ft_strlcat", test_ft_strlcat);
    run_test("ft_strnstr", test_ft_strnstr);
    run_test("ft_strlowcase", test_ft_tolower);
    run_test("ft_strupcase", test_ft_toupper);
    return 0;
}