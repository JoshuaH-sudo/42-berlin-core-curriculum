/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:24 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 14:53:56 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

int test_ft_memset(void)
{
    int ok = 1;

    // Test 1: Basic functionality with character
    char test1[20] = "hello world";
    char test2[20] = "hello world";

    ft_memset(test1, 'X', 5);
    memset(test2, 'X', 5);
    ok &= (memcmp(test1, test2, 20) == 0);
    printf("checked basic char fill: %d\n", ok);

    // Test 2: Fill entire buffer
    char buf1[10];
    char buf2[10];

    ft_memset(buf1, 'A', sizeof(buf1));
    memset(buf2, 'A', sizeof(buf2));
    ok &= (memcmp(buf1, buf2, sizeof(buf1)) == 0);
    printf("checked full buffer fill: %d\n", ok);

    // Test 3: Fill with zero
    char zero1[15] = "some test data";
    char zero2[15] = "some test data";

    ft_memset(zero1, 0, 10);
    memset(zero2, 0, 10);
    ok &= (memcmp(zero1, zero2, 15) == 0);
    printf("checked zero fill: %d\n", ok);

    // Test 4: Fill with byte value > 127
    unsigned char high1[8];
    unsigned char high2[8];

    ft_memset(high1, 255, sizeof(high1));
    memset(high2, 255, sizeof(high2));
    ok &= (memcmp(high1, high2, sizeof(high1)) == 0);
    printf("checked high byte value: %d\n", ok);

    // Test 5: Zero length
    char unchanged1[10] = "unchanged";
    char unchanged2[10] = "unchanged";

    ft_memset(unchanged1, 'Z', 0);
    memset(unchanged2, 'Z', 0);
    ok &= (memcmp(unchanged1, unchanged2, 10) == 0);
    printf("checked zero length: %d\n", ok);

    // Test 6: Integer array (testing byte-by-byte fill)
    int int_arr1[5] = {1, 2, 3, 4, 5};
    int int_arr2[5] = {1, 2, 3, 4, 5};

    ft_memset(int_arr1, 0, sizeof(int_arr1));
    memset(int_arr2, 0, sizeof(int_arr2));
    ok &= (memcmp(int_arr1, int_arr2, sizeof(int_arr1)) == 0);
    printf("checked integer array: %d\n", ok);

    return ok;
}

int test_ft_memcmp(void)
{
    int ok = 1;

    // Test 1: Equal strings
    char str1[] = "hello world";
    char str2[] = "hello world";

    int ft_result = ft_memcmp(str1, str2, 11);
    int std_result = memcmp(str1, str2, 11);
    ok &= ((ft_result == 0) == (std_result == 0));
    printf("checked equal strings: %d\n", ok);

    // Test 2: Different strings - first different
    char diff1[] = "abc";
    char diff2[] = "abd";

    ft_result = ft_memcmp(diff1, diff2, 3);
    std_result = memcmp(diff1, diff2, 3);
    ok &= ((ft_result < 0) == (std_result < 0));
    printf("checked first string smaller: %d\n", ok);

    // Test 3: Different strings - second different
    ft_result = ft_memcmp(diff2, diff1, 3);
    std_result = memcmp(diff2, diff1, 3);
    ok &= ((ft_result > 0) == (std_result > 0));
    printf("checked first string larger: %d\n", ok);

    // Test 4: Zero length comparison
    ft_result = ft_memcmp("abc", "xyz", 0);
    std_result = memcmp("abc", "xyz", 0);
    ok &= (ft_result == std_result);
    printf("checked zero length: %d\n", ok);

    // Test 5: Partial comparison
    char partial1[] = "abcdef";
    char partial2[] = "abcxyz";

    ft_result = ft_memcmp(partial1, partial2, 3);
    std_result = memcmp(partial1, partial2, 3);
    ok &= (ft_result == std_result);
    printf("checked partial equal: %d\n", ok);

    ft_result = ft_memcmp(partial1, partial2, 4);
    std_result = memcmp(partial1, partial2, 4);
    ok &= ((ft_result < 0) == (std_result < 0));
    printf("checked partial different: %d\n", ok);

    // Test 6: Binary data with null bytes
    unsigned char bin1[] = {0x01, 0x02, 0x00, 0x04, 0x05};
    unsigned char bin2[] = {0x01, 0x02, 0x00, 0x04, 0x05};
    unsigned char bin3[] = {0x01, 0x02, 0x00, 0x03, 0x05};

    ft_result = ft_memcmp(bin1, bin2, 5);
    std_result = memcmp(bin1, bin2, 5);
    ok &= (ft_result == std_result);
    printf("checked binary equal: %d\n", ok);

    ft_result = ft_memcmp(bin1, bin3, 5);
    std_result = memcmp(bin1, bin3, 5);
    ok &= ((ft_result > 0) == (std_result > 0));
    printf("checked binary different: %d\n", ok);

    // Test 7: Unsigned char comparison (important for values > 127)
    unsigned char high1[] = {200, 100};
    unsigned char high2[] = {100, 200};

    ft_result = ft_memcmp(high1, high2, 2);
    std_result = memcmp(high1, high2, 2);
    ok &= ((ft_result > 0) == (std_result > 0));
    printf("checked high byte values: %d\n", ok);

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

int test_ft_strchr(void)
{
    int ok = 1;

    // Test finding existing character
    char str[] = "hello world";
    char *res1 = ft_strchr(str, 'w');
    char *res2 = strchr(str, 'w');
    ok &= (res1 == res2);
    printf("checked finding 'w': %d\n", ok);

    // Test finding first character
    res1 = ft_strchr(str, 'h');
    res2 = strchr(str, 'h');
    ok &= (res1 == res2);
    printf("checked finding first char 'h': %d\n", ok);

    // Test finding last character (before null)
    res1 = ft_strchr(str, 'd');
    res2 = strchr(str, 'd');
    ok &= (res1 == res2);
    printf("checked finding last char 'd': %d\n", ok);

    // Test finding null terminator
    res1 = ft_strchr(str, '\0');
    res2 = strchr(str, '\0');
    ok &= (res1 == res2);
    printf("checked finding null terminator: %d\n", ok);

    // Test character not found
    res1 = ft_strchr(str, 'x');
    res2 = strchr(str, 'x');
    ok &= (res1 == res2); // Both should be NULL
    printf("checked char not found: %d\n", ok);

    // Test with empty string
    char empty[] = "";
    res1 = ft_strchr(empty, 'a');
    res2 = strchr(empty, 'a');
    ok &= (res1 == res2);
    printf("checked empty string: %d\n", ok);

    // Test finding null in empty string
    res1 = ft_strchr(empty, '\0');
    res2 = strchr(empty, '\0');
    ok &= (res1 == res2);
    printf("checked null in empty string: %d\n", ok);

    // Test with repeated characters (should find first)
    char repeated[] = "hello";
    res1 = ft_strchr(repeated, 'l');
    res2 = strchr(repeated, 'l');
    ok &= (res1 == res2);
    printf("checked repeated chars (first): %d\n", ok);

    return ok;
}

int test_ft_strrchr(void)
{
    int ok = 1;

    // Test finding existing character
    char str[] = "hello world";
    char *res1 = ft_strrchr(str, 'w');
    char *res2 = strrchr(str, 'w');
    ok &= (res1 == res2);
    printf("checked finding 'w': %d\n", ok);

    // Test finding last character (before null)
    res1 = ft_strrchr(str, 'd');
    res2 = strrchr(str, 'd');
    ok &= (res1 == res2);
    printf("checked finding last char 'd': %d\n", ok);

    // Test finding null terminator
    res1 = ft_strrchr(str, '\0');
    res2 = strrchr(str, '\0');
    ok &= (res1 == res2);
    printf("checked finding null terminator: %d\n", ok);

    // Test character not found
    res1 = ft_strrchr(str, 'x');
    res2 = strrchr(str, 'x');
    ok &= (res1 == res2); // Both should be NULL
    printf("checked char not found: %d\n", ok);

    // Test with repeated characters (should find last)
    char repeated[] = "hello";
    res1 = ft_strrchr(repeated, 'l');
    res2 = strrchr(repeated, 'l');
    ok &= (res1 == res2);
    printf("checked repeated chars (last): %d\n", ok);

    // Test with empty string
    char empty[] = "";
    res1 = ft_strrchr(empty, 'a');
    res2 = strrchr(empty, 'a');
    ok &= (res1 == res2);
    printf("checked empty string: %d\n", ok);

    // Test finding null in empty string
    res1 = ft_strrchr(empty, '\0');
    res2 = strrchr(empty, '\0');
    ok &= (res1 == res2);
    printf("checked null in empty string: %d\n", ok);

    // Test first character
    res1 = ft_strrchr(str, 'h');
    res2 = strrchr(str, 'h');
    ok &= (res1 == res2);
    printf("checked first char 'h': %d\n", ok);

    return ok;
}

int test_ft_strnstr(void)
{
    int ok = 1;

    // Test basic substring finding
    char haystack[] = "hello world world start";
    char needle[] = "world";
    char *res1 = ft_strnstr(haystack, needle, strlen(haystack));
    char *res2 = strnstr(haystack, needle, strlen(haystack));
    ok &= (res1 == res2 || (res1 && res2 && strcmp(res1, res2) == 0));
    printf("checked basic substring: %d\n", ok);

    // Test with length limit that includes the needle
    res1 = ft_strnstr(haystack, needle, 15); // Should find first "world"
    res2 = strnstr(haystack, needle, 15);
    ok &= (res1 && strncmp(res1, "world world start", 17) == 0);
    printf("checked with length limit (found): %d\n", ok);
    ok &= (res1 == res2 || (res1 && res2 && strcmp(res1, res2) == 0));
    printf("checked with length limit (found) strnstr match: %d\n", ok);

    // Test with length limit that excludes the needle
    res1 = ft_strnstr(haystack, needle, 5); // Too short to find "world"
    res2 = strnstr(haystack, needle, 5);
    ok &= (res1 == NULL);
    printf("checked with length limit (not found): %d\n", ok);
    ok &= (res1 == res2);
    printf("checked with length limit (not found) strnstr match: %d\n", ok);

    // Test empty needle (should return haystack)
    char empty_needle[] = "";
    res1 = ft_strnstr(haystack, empty_needle, strlen(haystack));
    res2 = strnstr(haystack, empty_needle, strlen(haystack));
    ok &= (res1 == haystack);
    printf("checked empty needle: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked empty needle strnstr match: %d\n", ok);

    // Test needle not found
    char not_found[] = "xyz";
    res1 = ft_strnstr(haystack, not_found, strlen(haystack));
    res2 = strnstr(haystack, not_found, strlen(haystack));
    ok &= (res1 == NULL);
    printf("checked needle not found: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked needle not found strnstr match: %d\n", ok);

    // Test needle longer than haystack
    char long_needle[] = "this is much longer than haystack";
    res1 = ft_strnstr("short", long_needle, 5);
    res2 = strnstr("short", long_needle, 5);
    ok &= (res1 == NULL);
    printf("checked needle longer than haystack: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked needle longer than haystack strnstr match: %d\n", ok);

    // Test with len = 0
    res1 = ft_strnstr(haystack, needle, 0);
    res2 = strnstr(haystack, needle, 0);
    ok &= (res1 == NULL);
    printf("checked with len = 0: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked with len = 0 strnstr match: %d\n", ok);

    // Test exact match with exact length
    char exact[] = "test";
    res1 = ft_strnstr("test", exact, 4);
    res2 = strnstr("test", exact, 4);
    ok &= (res1 && strcmp(res1, "test") == 0);
    printf("checked exact match: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked exact match strnstr match: %d\n", ok);

    // Test partial needle at end of length limit
    res1 = ft_strnstr("hello world", "worl", 10); // Should find "worl"
    res2 = strnstr("hello world", "worl", 10);
    ok &= (res1 && strncmp(res1, "world", 5) == 0);
    printf("checked partial at length limit: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked partial at length limit strnstr match: %d\n", ok);

    // Test needle that would be cut off by length limit
    res1 = ft_strnstr("hello world", "world", 9); // "world" starts at pos 6, but len=9 only goes to pos 8
    res2 = strnstr("hello world", "world", 9);
    ok &= (res1 == NULL);
    printf("checked needle cut off by length: %d\n", ok);
    ok &= (res1 == res2);
    printf("checked needle cut off by length strnstr match: %d\n", ok);

    return ok;
}

int test_ft_atoi(void)
{
    int ok = 1;
    
    // Test basic positive number
    int ft_result = ft_atoi("123");
    int std_result = atoi("123");
    ok &= (ft_result == std_result);
    printf("checked '123': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test basic negative number
    ft_result = ft_atoi("-456");
    std_result = atoi("-456");
    ok &= (ft_result == std_result);
    printf("checked '-456': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test zero
    ft_result = ft_atoi("0");
    std_result = atoi("0");
    ok &= (ft_result == std_result);
    printf("checked '0': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with leading whitespace
    ft_result = ft_atoi("   42");
    std_result = atoi("   42");
    ok &= (ft_result == std_result);
    printf("checked '   42': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with leading whitespace and sign
    ft_result = ft_atoi("  -789");
    std_result = atoi("  -789");
    ok &= (ft_result == std_result);
    printf("checked '  -789': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with positive sign
    ft_result = ft_atoi("+123");
    std_result = atoi("+123");
    ok &= (ft_result == std_result);
    printf("checked '+123': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with trailing non-digits
    ft_result = ft_atoi("42abc");
    std_result = atoi("42abc");
    ok &= (ft_result == std_result);
    printf("checked '42abc': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with no digits
    ft_result = ft_atoi("abc");
    std_result = atoi("abc");
    ok &= (ft_result == std_result);
    printf("checked 'abc': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test empty string
    ft_result = ft_atoi("");
    std_result = atoi("");
    ok &= (ft_result == std_result);
    printf("checked '': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with only whitespace
    ft_result = ft_atoi("   ");
    std_result = atoi("   ");
    ok &= (ft_result == std_result);
    printf("checked '   ': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with only sign
    ft_result = ft_atoi("-");
    std_result = atoi("-");
    ok &= (ft_result == std_result);
    printf("checked '-': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    ft_result = ft_atoi("+");
    std_result = atoi("+");
    ok &= (ft_result == std_result);
    printf("checked '+': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with multiple signs (should stop at first non-sign)
    ft_result = ft_atoi("--123");
    std_result = atoi("--123");
    ok &= (ft_result == std_result);
    printf("checked '--123': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    ft_result = ft_atoi("+-123");
    std_result = atoi("+-123");
    ok &= (ft_result == std_result);
    printf("checked '+-123': %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test with tabs and other whitespace
    ft_result = ft_atoi("\\t\\n\\r 123");
    std_result = atoi("\\t\\n\\r 123");
    ok &= (ft_result == std_result);
    printf("checked tab/newline/space: %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test large positive number
    ft_result = ft_atoi("2147483647");
    std_result = atoi("2147483647");
    ok &= (ft_result == std_result);
    printf("checked INT_MAX: %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    // Test large negative number
    ft_result = ft_atoi("-2147483648");
    std_result = atoi("-2147483648");
    ok &= (ft_result == std_result);
    printf("checked INT_MIN: %d (ft=%d, std=%d)\n", ok, ft_result, std_result);
    
    return ok;
}

int test_ft_strdup(void)
{
    int ok = 1;
    
    // Test basic string duplication
    char src[] = "hello world";
    char *ft_dup = ft_strdup(src);
    char *std_dup = strdup(src);
    ok &= (ft_dup != NULL && std_dup != NULL);
    ok &= (strcmp(ft_dup, std_dup) == 0);
    ok &= (ft_dup != src); // Should be different pointer
    printf("checked basic dup: %d (ft='%s', std='%s')\n", ok, ft_dup ? ft_dup : "NULL", std_dup ? std_dup : "NULL");
    free(ft_dup);
    free(std_dup);
    
    // Test empty string
    char empty[] = "";
    ft_dup = ft_strdup(empty);
    std_dup = strdup(empty);
    ok &= (ft_dup != NULL && std_dup != NULL);
    ok &= (strcmp(ft_dup, std_dup) == 0);
    ok &= (strlen(ft_dup) == 0 && strlen(std_dup) == 0);
    printf("checked empty string: %d (ft='%s', std='%s')\n", ok, ft_dup ? ft_dup : "NULL", std_dup ? std_dup : "NULL");
    free(ft_dup);
    free(std_dup);
    
    // Test single character
    char single[] = "a";
    ft_dup = ft_strdup(single);
    std_dup = strdup(single);
    ok &= (ft_dup != NULL && std_dup != NULL);
    ok &= (strcmp(ft_dup, std_dup) == 0);
    ok &= (strlen(ft_dup) == 1 && strlen(std_dup) == 1);
    printf("checked single char: %d (ft='%s', std='%s')\n", ok, ft_dup ? ft_dup : "NULL", std_dup ? std_dup : "NULL");
    free(ft_dup);
    free(std_dup);
    
    // Test string with special characters
    char special[] = "hello\tworld\n!@#$%^&*()";
    ft_dup = ft_strdup(special);
    std_dup = strdup(special);
    ok &= (ft_dup != NULL && std_dup != NULL);
    ok &= (strcmp(ft_dup, std_dup) == 0);
    printf("checked special chars: %d\n", ok);
    free(ft_dup);
    free(std_dup);
    
    // Test longer string
    char long_str[] = "This is a much longer string to test the duplication of longer content and ensure it works properly";
    ft_dup = ft_strdup(long_str);
    std_dup = strdup(long_str);
    ok &= (ft_dup != NULL && std_dup != NULL);
    ok &= (strcmp(ft_dup, std_dup) == 0);
    ok &= (strlen(ft_dup) == strlen(long_str));
    printf("checked long string: %d (len=%lu)\n", ok, strlen(ft_dup));
    free(ft_dup);
    free(std_dup);
    
    return ok;
}

int test_ft_calloc(void)
{
    int ok = 1;
    
    // Test basic allocation - integers
    int *ft_mem = (int *)ft_calloc(5, sizeof(int));
    int *std_mem = (int *)calloc(5, sizeof(int));
    ok &= (ft_mem != NULL && std_mem != NULL);
    // Check that memory is zeroed
    int ft_zero = 1, std_zero = 1;
    for (int i = 0; i < 5; i++) {
        if (ft_mem[i] != 0) ft_zero = 0;
        if (std_mem[i] != 0) std_zero = 0;
    }
    ok &= (ft_zero && std_zero);
    printf("checked int calloc: %d (zeroed: ft=%d, std=%d)\n", ok, ft_zero, std_zero);
    free(ft_mem);
    free(std_mem);
    
    // Test character array allocation
    char *ft_chars = (char *)ft_calloc(10, sizeof(char));
    char *std_chars = (char *)calloc(10, sizeof(char));
    ok &= (ft_chars != NULL && std_chars != NULL);
    // Check that memory is zeroed
    ft_zero = 1, std_zero = 1;
    for (int i = 0; i < 10; i++) {
        if (ft_chars[i] != '\0') ft_zero = 0;
        if (std_chars[i] != '\0') std_zero = 0;
    }
    ok &= (ft_zero && std_zero);
    printf("checked char calloc: %d (zeroed: ft=%d, std=%d)\n", ok, ft_zero, std_zero);
    free(ft_chars);
    free(std_chars);
    
    // Test zero count
    ft_mem = (int *)ft_calloc(0, sizeof(int));
    std_mem = (int *)calloc(0, sizeof(int));
    // Both should either return NULL or a valid pointer that can be freed
    // The behavior is implementation-defined, so we just check they behave the same
    ok &= ((ft_mem == NULL) == (std_mem == NULL));
    printf("checked zero count: %d (ft=%p, std=%p)\n", ok, (void*)ft_mem, (void*)std_mem);
    if (ft_mem) free(ft_mem);
    if (std_mem) free(std_mem);
    
    // Test zero size
    ft_mem = (int *)ft_calloc(5, 0);
    std_mem = (int *)calloc(5, 0);
    ok &= ((ft_mem == NULL) == (std_mem == NULL));
    printf("checked zero size: %d (ft=%p, std=%p)\n", ok, (void*)ft_mem, (void*)std_mem);
    if (ft_mem) free(ft_mem);
    if (std_mem) free(std_mem);
    
    // Test single element
    ft_mem = (int *)ft_calloc(1, sizeof(int));
    std_mem = (int *)calloc(1, sizeof(int));
    ok &= (ft_mem != NULL && std_mem != NULL);
    ok &= (*ft_mem == 0 && *std_mem == 0);
    printf("checked single element: %d (ft=%d, std=%d)\n", ok, *ft_mem, *std_mem);
    free(ft_mem);
    free(std_mem);
    
    // Test larger allocation
    size_t large_count = 1000;
    ft_chars = (char *)ft_calloc(large_count, sizeof(char));
    std_chars = (char *)calloc(large_count, sizeof(char));
    ok &= (ft_chars != NULL && std_chars != NULL);
    // Check first, middle, and last elements are zero
    ok &= (ft_chars[0] == 0 && ft_chars[large_count/2] == 0 && ft_chars[large_count-1] == 0);
    ok &= (std_chars[0] == 0 && std_chars[large_count/2] == 0 && std_chars[large_count-1] == 0);
    printf("checked large allocation: %d (count=%lu)\n", ok, large_count);
    free(ft_chars);
    free(std_chars);
    
    return ok;
}

int test_ft_calloc_edge_cases(void)
{
    int ok = 1;
    
    // Test that calloc(0, size) returns a valid pointer that can be freed
    void *ft_ptr1 = ft_calloc(0, sizeof(int));
    void *std_ptr1 = calloc(0, sizeof(int));
    
    // Both should behave the same way (either both NULL or both non-NULL)
    ok &= ((ft_ptr1 == NULL) == (std_ptr1 == NULL));
    printf("checked calloc(0, sizeof(int)): %d (ft=%p, std=%p)\n", ok, ft_ptr1, std_ptr1);
    
    // If non-NULL, should be safely freeable
    if (ft_ptr1) {
        free(ft_ptr1);  // This should not crash
        printf("ft_calloc(0, size) pointer freed successfully\n");
    }
    if (std_ptr1) {
        free(std_ptr1);
    }
    
    // Test that calloc(count, 0) returns a valid pointer that can be freed
    void *ft_ptr2 = ft_calloc(5, 0);
    void *std_ptr2 = calloc(5, 0);
    
    ok &= ((ft_ptr2 == NULL) == (std_ptr2 == NULL));
    printf("checked calloc(5, 0): %d (ft=%p, std=%p)\n", ok, ft_ptr2, std_ptr2);
    
    // If non-NULL, should be safely freeable
    if (ft_ptr2) {
        free(ft_ptr2);  // This should not crash
        printf("ft_calloc(count, 0) pointer freed successfully\n");
    }
    if (std_ptr2) {
        free(std_ptr2);
    }
    
    // Test that calloc(0, 0) returns a valid pointer that can be freed
    void *ft_ptr3 = ft_calloc(0, 0);
    void *std_ptr3 = calloc(0, 0);
    
    ok &= ((ft_ptr3 == NULL) == (std_ptr3 == NULL));
    printf("checked calloc(0, 0): %d (ft=%p, std=%p)\n", ok, ft_ptr3, std_ptr3);
    
    // If non-NULL, should be safely freeable
    if (ft_ptr3) {
        free(ft_ptr3);  // This should not crash
        printf("ft_calloc(0, 0) pointer freed successfully\n");
    }
    if (std_ptr3) {
        free(std_ptr3);
    }
    
    // Test multiple allocations to ensure each returns unique pointers
    void *ft_ptr4 = ft_calloc(0, 1);
    void *ft_ptr5 = ft_calloc(0, 1);
    
    // If both are non-NULL, they should be different (unique pointers)
    if (ft_ptr4 && ft_ptr5) {
        ok &= (ft_ptr4 != ft_ptr5);
        printf("checked unique pointers for zero-size allocs: %d\n", ok);
    }
    
    if (ft_ptr4) free(ft_ptr4);
    if (ft_ptr5) free(ft_ptr5);
    
    return ok;
}

int test_ft_tolower(void)
{
    int ok = 1;

    // Test uppercase letters
    ok &= (ft_tolower('A') == tolower('A'));
    printf("checked 'A': %d\n", ok);
    ok &= (ft_tolower('Z') == tolower('Z'));
    printf("checked 'Z': %d\n", ok);
    ok &= (ft_tolower('M') == tolower('M'));
    printf("checked 'M': %d\n", ok);

    // Test lowercase letters (should remain unchanged)
    ok &= (ft_tolower('a') == tolower('a'));
    printf("checked 'a': %d\n", ok);
    ok &= (ft_tolower('z') == tolower('z'));
    printf("checked 'z': %d\n", ok);
    ok &= (ft_tolower('m') == tolower('m'));
    printf("checked 'm': %d\n", ok);

    // Test non-alphabetic characters (should remain unchanged)
    ok &= (ft_tolower('0') == tolower('0'));
    printf("checked '0': %d\n", ok);
    ok &= (ft_tolower('9') == tolower('9'));
    printf("checked '9': %d\n", ok);
    ok &= (ft_tolower('!') == tolower('!'));
    printf("checked '!': %d\n", ok);
    ok &= (ft_tolower(' ') == tolower(' '));
    printf("checked space: %d\n", ok);
    ok &= (ft_tolower('@') == tolower('@'));
    printf("checked '@': %d\n", ok);

    // Test edge cases
    ok &= (ft_tolower(0) == tolower(0));
    printf("checked null char: %d\n", ok);
    ok &= (ft_tolower(127) == tolower(127));
    printf("checked 127: %d\n", ok);

    return ok;
}

int test_ft_toupper(void)
{
    int ok = 1;

    // Test lowercase letters
    ok &= (ft_toupper('a') == toupper('a'));
    printf("checked 'a': %d\n", ok);
    ok &= (ft_toupper('z') == toupper('z'));
    printf("checked 'z': %d\n", ok);
    ok &= (ft_toupper('m') == toupper('m'));
    printf("checked 'm': %d\n", ok);

    // Test uppercase letters (should remain unchanged)
    ok &= (ft_toupper('A') == toupper('A'));
    printf("checked 'A': %d\n", ok);
    ok &= (ft_toupper('Z') == toupper('Z'));
    printf("checked 'Z': %d\n", ok);
    ok &= (ft_toupper('M') == toupper('M'));
    printf("checked 'M': %d\n", ok);

    // Test non-alphabetic characters (should remain unchanged)
    ok &= (ft_toupper('0') == toupper('0'));
    printf("checked '0': %d\n", ok);
    ok &= (ft_toupper('9') == toupper('9'));
    printf("checked '9': %d\n", ok);
    ok &= (ft_toupper('!') == toupper('!'));
    printf("checked '!': %d\n", ok);
    ok &= (ft_toupper(' ') == toupper(' '));
    printf("checked space: %d\n", ok);
    ok &= (ft_toupper('@') == toupper('@'));
    printf("checked '@': %d\n", ok);

    // Test edge cases
    ok &= (ft_toupper(0) == toupper(0));
    printf("checked null char: %d\n", ok);
    ok &= (ft_toupper(127) == toupper(127));
    printf("checked 127: %d\n", ok);

    return ok;
}

int test_ft_strlcpy(void)
{
    int ok = 1;

    // Test basic functionality - compare return value and result
    char src[] = "hello, world!";
    char dest1[20];
    unsigned int ret1 = ft_strlcpy(dest1, src, sizeof(dest1));
    unsigned int expected_ret = strlen(src);
    ok &= (strcmp(dest1, src) == 0) && (ret1 == expected_ret);
    printf("checked basic copy: %d (ret1=%d, expected=%d, dest='%s')\n", ok, ret1, expected_ret, dest1);

    // Test size smaller than source - should truncate but return full source length
    char dest3[6];
    unsigned int ret3 = ft_strlcpy(dest3, src, sizeof(dest3));
    ok &= (strncmp(dest3, "hello", 5) == 0) && (dest3[5] == '\0') && (ret3 == strlen(src));
    printf("checked truncated copy: %d (ret3=%d, expected=%d, dest='%s')\n", ok, ret3, (unsigned int)strlen(src), dest3);

    // Test size 0 - should not modify dest, but return source length
    char dest4[20] = "unchanged";
    unsigned int ret4 = ft_strlcpy(dest4, src, 0);
    ok &= (strcmp(dest4, "unchanged") == 0) && (ret4 == strlen(src));
    printf("checked size 0: %d (ret4=%d, expected=%d, dest='%s')\n", ok, ret4, (unsigned int)strlen(src), dest4);

    // Test empty source
    char empty[] = "";
    char dest5[10];
    unsigned int ret5 = ft_strlcpy(dest5, empty, sizeof(dest5));
    ok &= (strcmp(dest5, "") == 0) && (ret5 == 0);
    printf("checked empty source: %d (ret5=%d, dest='%s')\n", ok, ret5, dest5);

    // Test exact size match
    char dest6[14]; // exactly strlen("hello, world!") + 1
    unsigned int ret6 = ft_strlcpy(dest6, src, sizeof(dest6));
    ok &= (strcmp(dest6, src) == 0) && (ret6 == strlen(src));
    printf("checked exact size: %d (ret6=%d, dest='%s')\n", ok, ret6, dest6);

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
    run_test("ft_bzero", test_ft_bzero);
    run_test("ft_isalpha", test_ft_isalpha);
    run_test("ft_isascii", test_ft_isascii);
    run_test("ft_isdigit", test_ft_isdigit);
    run_test("ft_isprint", test_ft_isprint);
    run_test("ft_tolower", test_ft_tolower);
    run_test("ft_toupper", test_ft_toupper);
    run_test("ft_strlen", test_ft_strlen);
    run_test("ft_strchr", test_ft_strchr);
    run_test("ft_strrchr", test_ft_strrchr);
    run_test("ft_strncmp", test_ft_strncmp);
    run_test("ft_strnstr", test_ft_strnstr);
    run_test("ft_strlcpy", test_ft_strlcpy);
    run_test("ft_strlcat", test_ft_strlcat);
    run_test("ft_memcpy", test_ft_memcpy);
    run_test("ft_memmove", test_ft_memmove);
    run_test("ft_memset", test_ft_memset);
    run_test("ft_memcmp", test_ft_memcmp);
    run_test("ft_memchr", test_ft_memchr);
    run_test("ft_atoi", test_ft_atoi);
    run_test("ft_strdup", test_ft_strdup);
    run_test("ft_calloc", test_ft_calloc);
    run_test("ft_calloc_edge_cases", test_ft_calloc_edge_cases);
    return 0;
}