#include "ft_printf.h"
#include <stdio.h>

void    compare_outputs(int ft_result, int std_result)
{
    if (ft_result == std_result)
        printf("[PASS]: ft_printf returned %d, printf returned %d\n", ft_result, std_result);
    else
        printf("[FAIL]: ft_printf returned %d, printf returned %d\n", ft_result, std_result);
}

int main()
{
    int dec_num = 42;
    int oct_num = 052;
    int hex_num = 0x2A;
    unsigned int unassigned_int = (unsigned int)(-1);
    int result1 = 0;
    int result2 = 0;
    result1 = printf("printf:\nhello c: %c, s: %s AAAA, p: %p\n", '!', "joshuahoban", &dec_num);
    result2 = printf("printf:\nhello c: %c, s: %s AAAA, p: %p\n", '!', "joshuahoban", &dec_num);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = ft_printf("ft_printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", dec_num, oct_num, hex_num);
    result2 = printf("printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", dec_num, oct_num, hex_num);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = ft_printf("ft_printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", dec_num, oct_num, hex_num);
    result2 = printf("printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", dec_num, oct_num, hex_num);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = ft_printf("ft_printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", -dec_num, -oct_num, -hex_num);
    result2 = printf("printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", -dec_num, -oct_num, -hex_num);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = ft_printf("ft_printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", -dec_num, -oct_num, -hex_num);
    result2 = printf("printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", -dec_num, -oct_num, -hex_num);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = printf("printf i: %i, u(unsigned): %u\n", unassigned_int, unassigned_int);
    result2 = ft_printf("ft_printf i: %i, u(unsigned): %u\n", unassigned_int, unassigned_int);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = printf("printf x(lowercase hex): %x, X(uppercase hex): %X\n", hex_num, hex_num);
    result2 = ft_printf("ft_printf x(lowercase hex): %x, X(uppercase hex): %X\n", hex_num, hex_num);
    compare_outputs(result1, result2);
    printf("\n---\n");
    result1 = ft_printf("ft_printf percent sign: %%\n");
    result2 = printf("printf percent sign: %%\n");
    compare_outputs(result1, result2);
    return 0;
}