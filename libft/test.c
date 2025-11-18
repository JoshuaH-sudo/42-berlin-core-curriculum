/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:24 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/18 20:31:27 by jhoban           ###   ########.fr       */
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
    int ok = 1;
    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];
    
    ft_memcpy(dest1, src, sizeof(src));
    memcpy(dest2, src, sizeof(src));
    // use memcmp to test because dest may not be null-terminated
    ok &= (memcmp(dest1, dest2, sizeof(src)) == 0);
    printf("checked full copy: %d\n", ok);

    char dest3[5];
    char dest4[5];
    ft_memcpy(dest3, src, sizeof(dest3));
    memcpy(dest4, src, sizeof(dest4));
    ok &= (memcmp(dest3, dest4, sizeof(dest3)) == 0);
    printf("checked partial copy: %d\n", ok);
    
    return ok;
}

int test_ft_memmove(void)
{
    int ok = 1;
    
    // Test 1: Non-overlapping memory (should work like memcpy)
    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];
    
    ft_memmove(dest1, src, strlen(src) + 1);
    memmove(dest2, src, strlen(src) + 1);
    ok &= (memcmp(dest1, dest2, strlen(src) + 1) == 0);
    printf("checked non-overlapping copy: %d\n", ok);
    
    // Test 2: Overlapping memory - source before destination
    char overlap1[] = "1234567890";
    char overlap2[] = "1234567890";
    
    // Move "34567" to position starting at "67"
    ft_memmove(overlap1 + 5, overlap1 + 2, 5);
    memmove(overlap2 + 5, overlap2 + 2, 5);
    ok &= (memcmp(overlap1, overlap2, 10) == 0);
    printf("checked overlapping src < dest: %d\n", ok);
    
    // Test 3: Overlapping memory - destination before source
    char overlap3[] = "1234567890";
    char overlap4[] = "1234567890";
    
    // Move "45678" to position starting at "23"
    ft_memmove(overlap3 + 1, overlap3 + 3, 5);
    memmove(overlap4 + 1, overlap4 + 3, 5);
    ok &= (memcmp(overlap3, overlap4, 10) == 0);
    printf("checked overlapping dest < src: %d\n", ok);
    
    // Test 4: Integer array test
    int int_src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int int_dest1[10];
    int int_dest2[10];
    
    ft_memmove(int_dest1, int_src, sizeof(int_src));
    memmove(int_dest2, int_src, sizeof(int_src));
    ok &= (memcmp(int_dest1, int_dest2, sizeof(int_src)) == 0);
    printf("checked integer array copy: %d\n", ok);
    
    // Test 5: Overlapping integer array
    int int_overlap1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int int_overlap2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    // Move 4 integers from position 2 to position 5
    ft_memmove(&int_overlap1[5], &int_overlap1[2], 4 * sizeof(int));
    memmove(&int_overlap2[5], &int_overlap2[2], 4 * sizeof(int));
    ok &= (memcmp(int_overlap1, int_overlap2, sizeof(int_overlap1)) == 0);
    printf("checked overlapping integer array: %d\n", ok);
    
    // Test 6: Zero bytes
    char zero_test1[] = "unchanged";
    char zero_test2[] = "unchanged";
    
    ft_memmove(zero_test1 + 2, zero_test1 + 5, 0);
    memmove(zero_test2 + 2, zero_test2 + 5, 0);
    ok &= (memcmp(zero_test1, zero_test2, sizeof(zero_test1)) == 0);
    printf("checked zero bytes: %d\n", ok);
    
    // Test 7: Same source and destination
    char same_test1[] = "no change";
    char same_test2[] = "no change";
    
    ft_memmove(same_test1, same_test1, strlen(same_test1));
    memmove(same_test2, same_test2, strlen(same_test2));
    ok &= (memcmp(same_test1, same_test2, sizeof(same_test1)) == 0);
    printf("checked same src/dest: %d\n", ok);
    
    return ok;
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
    int ok = 1;
    ok &= (ft_strncmp("abc", "abc", 3) == strncmp("abc", "abc", 3));
    printf("checked equal: %d\n", ok);
    ok &= (ft_strncmp("abc", "abd", 3) == strncmp("abc", "abd", 3));
    printf("checked diff: %d\n", ok);
    ok &= (ft_strncmp("abc", "abc", 0) == strncmp("abc", "abc", 0));
    printf("checked n=0: %d\n", ok);
    // We don't compare to strncmp here because its behavior with empty strings can vary
    ok &= (ft_strncmp("abc", "", 2) != 0 && strncmp("abc", "", 2) != 0);
    printf("checked vs empty: %d\n", ok);
    return ok;
}

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
    
    return (ok);
}

int test_ft_strlcpy(void)
{
    int ok = 1;
    
    // Test basic functionality
    char src[] = "hello, world!";
    char dest1[20];
    char dest2[20];
    unsigned int ret1 = ft_strlcpy(dest1, src, sizeof(dest1));
    unsigned int ret2 = strlen(src); // strlcpy should return source length
    ok &= (strcmp(dest1, src) == 0) && (strcmp(dest2, src) == 0) && (ret1 == ret2);
    printf("checked basic copy: %d (ret1=%d, ret2=%d)\n", ok, ret1, ret2);
    
    // Test size smaller than source
    char dest3[6];
    unsigned int ret3 = ft_strlcpy(dest3, src, sizeof(dest3));
    ok &= (strncmp(dest3, "hello", 5) == 0) && (dest3[5] == '\0') && (ret3 == strlen(src));
    printf("checked truncated copy: %d\n", ok);
    
    // Test size 0
    char dest4[20] = "unchanged";
    unsigned int ret4 = ft_strlcpy(dest4, src, 0);
    ok &= (strcmp(dest4, "unchanged") == 0) && (ret4 == strlen(src));
    printf("checked size 0: %d\n", ok);
    
    // Test empty source
    char empty[] = "";
    char dest5[10];
    unsigned int ret5 = ft_strlcpy(dest5, empty, sizeof(dest5));
    ok &= (strcmp(dest5, "") == 0) && (ret5 == 0);
    printf("checked empty source: %d\n", ok);
    
    return ok;
}

int test_ft_strlcat(void)
{
    int ok = 1;
    
    // Test basic concatenation
    char dest1[20] = "hello ";
    char src[] = "world";
    unsigned int ret1 = ft_strlcat(dest1, src, sizeof(dest1));
    unsigned int expected_ret1 = strlen("hello ") + strlen("world");
    ok &= (strcmp(dest1, "hello world") == 0) && (ret1 == expected_ret1);
    printf("checked basic cat: %d (ret=%d, expected=%d)\n", ok, ret1, expected_ret1);
    
    // Test size limit
    char dest2[10] = "hello ";
    unsigned int ret2 = ft_strlcat(dest2, "world!", sizeof(dest2));
    ok &= (strcmp(dest2, "hello wor") == 0) && (dest2[9] == '\0') && (ret2 == strlen("hello ") + strlen("world!"));
    printf("checked size limit: %d (result='%s')\n", ok, dest2);
    
    // Test dest length >= size
    char dest3[5] = "hello";
    unsigned int ret3 = ft_strlcat(dest3, "world", 3);
    unsigned int expected_ret3 = 3 + strlen("world"); // size + src_len when dest_len >= size
    ok &= (ret3 == expected_ret3);
    printf("checked dest >= size: %d\n", ok);
    
    // Test empty source
    char dest4[20] = "hello";
    unsigned int ret4 = ft_strlcat(dest4, "", sizeof(dest4));
    ok &= (strcmp(dest4, "hello") == 0) && (ret4 == strlen("hello"));
    printf("checked empty src: %d\n", ok);
    
    return ok;
}

int main(void)
{
    // run_test("ft_bzero", test_ft_bzero);
    run_test("ft_memcpy", test_ft_memcpy);
    run_test("ft_memmove", test_ft_memmove);
    /*
    run_test("ft_memchr", test_ft_memchr);
    run_test("ft_isalpha", test_ft_isalpha);
    run_test("ft_isascii", test_ft_isascii);
    run_test("ft_isdigit", test_ft_isdigit);
    run_test("ft_isprint", test_ft_isprint);
    run_test("ft_strlen", test_ft_strlen);
    run_test("ft_strncmp", test_ft_strncmp);
    run_test("ft_strnstr", test_ft_strnstr);
    run_test("ft_tolower", test_ft_tolower);
    run_test("ft_toupper", test_ft_toupper);
    run_test("ft_strlcpy", test_ft_strlcpy);
    run_test("ft_strlcat", test_ft_strlcat);
    */
    return 0;
}