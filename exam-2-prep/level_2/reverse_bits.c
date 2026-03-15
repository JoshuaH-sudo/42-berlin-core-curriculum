/* Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100 */

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0')

#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
//    unsigned char result = 0;

//   int i = 0;
//   while (i < 8)
//   {
//         if ((octet >> i) & 1)
//         {
//             // printf("Bit %d is 1\n", i);
//             result = (result >> 1);
//             result = result | 128;
//         }
//         // printf("octet << %d "BYTE_TO_BINARY_PATTERN, i, BYTE_TO_BINARY(octet << i));
//         // printf("\n");
//         // printf("result %d: "BYTE_TO_BINARY_PATTERN, i, BYTE_TO_BINARY(result));
//         // printf("\n");
//         i++;
//   }

//   return result;

  	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
        printf("octet: %d "BYTE_TO_BINARY_PATTERN, octet, BYTE_TO_BINARY(octet));
        printf("\n");
        printf("res: %d "BYTE_TO_BINARY_PATTERN, res, BYTE_TO_BINARY(res));
        printf("\n");
        printf("octet %% 2 = %d\n", octet % 2);
        printf("res * 2 = %d\n", res * 2);
        printf("res * 2 + (octet %% 2) = %d\n", res * 2 + (octet % 2));
        printf("octet / 2 = %d\n", octet / 2);
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int main()
{
    // printf("128: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(128));
    // printf("\n");
    printf("Input: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(9));
    printf("\n");
    unsigned char result = reverse_bits(9);
    printf("Result: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(result));
    printf("\n");
}