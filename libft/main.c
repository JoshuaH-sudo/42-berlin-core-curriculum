#include "libft.h"
#include <stdio.h>

int main(void)
{
    char str[50] = "Hello, World!";
    ft_bzero(str, 5);
    // Should print ", World!"
    printf("Resulting string: '%s'\n", str); 
    return 0;
}