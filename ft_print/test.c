#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int num = 42;
    ft_printf("printf\nhello c: %c, s: %s AAAA, p: %p, d: %d", '!', "joshuahoban", &num, num);
    printf("\n");
    printf("printf:\nhello c: %c, s: %s AAAA, p: %p, d: %d", '!', "joshuahoban", &num, num);
}