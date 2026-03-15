/* Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */

int	    is_power_of_2(unsigned int n)
{
    // Bitwise AND of n and (n - 1) will be 0 if n is a power of 2, and n must not be 0
    // For example:
    // n = 4 (00000100 in binary), n - 1 = 3 (00000011 in binary), n & (n - 1) = 0
    // n = 5 (00000101 in binary), n - 1 = 4 (00000100 in binary), n & (n - 1) = 4 (not 0)
    // if it is an odd number, it cannot be a power of 2, except for 1 (2^0)
    // return (n != 0 && (n & (n - 1)) == 0);
    if (n == 0)
        return 0;
    while (n % 2 == 0)
        n /= 2;
    return (n == 1);
}

#include <stdio.h>
int main()
{
    unsigned int n1 = 1; // 2^0
    unsigned int n2 = 2; // 2^1
    unsigned int n3 = 3; // Not a power of 2
    unsigned int n4 = 4; // 2^2
    unsigned int n5 = 5; // Not a power of 2
    unsigned int n6 = 8; // 2^3
    unsigned int n7 = 16; // 2^4
    unsigned int n8 = 0; // Not a power of 2

    printf("is_power_of_2(%u) = %d\n", n1, is_power_of_2(n1)); // Should return 1
    printf("is_power_of_2(%u) = %d\n", n2, is_power_of_2(n2)); // Should return 1
    printf("is_power_of_2(%u) = %d\n", n3, is_power_of_2(n3)); // Should return 0
    printf("is_power_of_2(%u) = %d\n", n4, is_power_of_2(n4)); // Should return 1
    printf("is_power_of_2(%u) = %d\n", n5, is_power_of_2(n5)); // Should return 0
    printf("is_power_of_2(%u) = %d\n", n6, is_power_of_2(n6)); // Should return 1
    printf("is_power_of_2(%u) = %d\n", n7, is_power_of_2(n7)); // Should return 1
    printf("is_power_of_2(%u) = %d\n", n8, is_power_of_2(n8)); // Should return 0

    return 0;
}