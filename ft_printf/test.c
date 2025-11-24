#include "ft_printf.h"
#include <stdio.h>

#define TEST(format, ...) \
	do { \
		int ft_res = ft_printf(format, ##__VA_ARGS__); \
		int std_res = printf(format, ##__VA_ARGS__); \
		if (ft_res == std_res) \
			printf("[PASS]: ft_printf returned %d, printf returned %d\n", ft_res, std_res); \
		else { \
			printf("[FAIL]: ft_printf returned %d, printf returned %d\n", ft_res, std_res); \
			result = 0; \
		} \
	} while (0)

int main()
{
    int dec_num = 42;
    int oct_num = 052;
    int hex_num = 0x2A;
    unsigned int unassigned_int = (unsigned int)(-1);
    int result = 1;
    void *ptr = NULL;
    printf("Starting ft_printf tests...\n");

    printf("ft_printf\n");
    int res1 = ft_printf(" NULL %s NULL ", NULL); 
    printf("\n");
    printf("printf\n");
    // int res2 = printf(" NULL %s NULL ", NULL); 
    printf("\n");
    printf("ft_printf returned: %d\n", res1);
    // printf("printf returned: %d\n", res2);
    
    // printf("printf:\nc: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, %%: %%\n", 'A', "test", ptr, dec_num, dec_num, unassigned_int, hex_num, hex_num);
    // ft_printf("ft_printf:\nc: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, %%: %%\n", 'A', "test", ptr, dec_num, dec_num, unassigned_int, hex_num, hex_num);
    // printf("\n%%c / %%s ---\n");
    // TEST("hello c: %c, s: %s AAAA\n", '!', "joshuahoban");
    // printf("\n%%p ---\n");
    // TEST("hello p: %p, p(null): %p\n", &dec_num, ptr);
    // printf("\n%%d ---\n");
    // TEST("fd(dec): %d, d(oct_num): %d, d(hex_num): %d\n", dec_num, oct_num, hex_num);
    // printf("\n%%i ---\n");
    // TEST("i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", dec_num, oct_num, hex_num);
    // printf("\n%%d ---\n");
    // TEST("d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", -dec_num, -oct_num, -hex_num);
    // printf("\n%%i neg ---\n");
    // TEST("i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", -dec_num, -oct_num, -hex_num);
    // printf("\n%%u ---\n");
    // TEST("u(unsigned): %u\n", unassigned_int);
    // printf("\n%%x %%X ---\n");
    // TEST("x(lowercase hex): %x, X(uppercase hex): %X\n", hex_num, hex_num);
    // printf("\n%% ---\n");
    // TEST("percent sign: %%\n");
    
    // if (result)
    //     printf("\nAll tests passed!\n");
    // else
    //     printf("\nSome tests failed.\n");
    return 0;
}