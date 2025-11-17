#include <strings.h>

void  ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    size_t i;

    ptr = (unsigned char *)s;
    for (i = 0; i < n; i++)
    {
        ptr[i] = 0;
    }
}
