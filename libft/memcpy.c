#include <string.h>

void  *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;
    int i;

    d = dest;
    s = src;
    i = 0;
    while (i < (int)n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}