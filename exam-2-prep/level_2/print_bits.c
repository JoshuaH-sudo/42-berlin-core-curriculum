/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010" */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 7;
    while (i >= 0)
    {
        if ((octet >> i) & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i--;
    }
}

#include <stdio.h>

int main()
{

    // a = 5 (00000101 in 8-bit binary)
    // b = 9 (00001001 in 8-bit binary)
    unsigned int a = 5, b = 9;

    // The result is 00000001 AND
    printf("a&b = %u\n", a & b);

    // The result is 00001101 OR
    printf("a|b = %u\n", a | b);

    // The result is 00001100 XOR
    printf("a^b = %u\n", a ^ b);

    // The result is 11111111111111111111111111111010 (assuming 32-bit unsigned int) NOT
    printf("~a = %u\n", a = ~a);

    // The result is 00010010 LEFT SHIFT
    printf("b<<1 = %u\n", b << 1);

    // The result is 00000100 RIGHT SHIFT
    printf("b>>1 = %u\n", b >> 1);
    print_bits(5);
    write(1, "\n", 1);
    print_bits(9);
    write(1, "\n", 1);
    return 0;
}