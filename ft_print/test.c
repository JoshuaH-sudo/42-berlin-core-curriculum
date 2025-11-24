#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int dec_num = 42;
    int oct_num = 052;
    int hex_num = 0x2A;
    unsigned int unassigned_int = (unsigned int)(-1);
    ft_printf("printf\nhello c: %c, s: %s AAAA, p: %p\n", '!', "joshuahoban", &dec_num);
    printf("\n---\n");
    printf("printf:\nhello c: %c, s: %s AAAA, p: %p\n", '!', "joshuahoban", &dec_num);
    printf("\n---\n");
    ft_printf("ft_printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", dec_num, oct_num, hex_num);
    printf("printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", dec_num, oct_num, hex_num);
    printf("\n---\n");
    ft_printf("ft_printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", dec_num, oct_num, hex_num);
    printf("printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", dec_num, oct_num, hex_num);
    printf("\n---\n");
    ft_printf("ft_printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", -dec_num, -oct_num, -hex_num);
    printf("printf d(dec): %d, d(oct_num): %d, d(hex_num): %d\n", -dec_num, -oct_num, -hex_num);
    printf("\n---\n");
    ft_printf("ft_printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", -dec_num, -oct_num, -hex_num);
    printf("printf i(dec): %i, i(oct_num): %i, i(hex_num): %i\n", -dec_num, -oct_num, -hex_num);
    printf("\n---\n");
    printf("printf i: %i, u(unsigned): %u\n", unassigned_int, unassigned_int);
    ft_printf("ft_printf i: %i, u(unsigned): %u\n", unassigned_int, unassigned_int);
    printf("\n---\n");
    printf("printf x(lowercase hex): %x, X(uppercase hex): %X\n", hex_num, hex_num);
    ft_printf("ft_printf x(lowercase hex): %x, X(uppercase hex): %X\n", hex_num, hex_num);
    printf("\n---\n");
    ft_printf("ft_printf percent sign: %%\n");
    printf("printf percent sign: %%\n");
    return 0;
}