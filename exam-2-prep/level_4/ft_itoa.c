#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int nbr)
{
    int isNeg = 0;
    int i = 0;
    int len = 0;

    if (nbr == -2147483648)
        return("-2147483648");
    if (nbr == 0)
        return("0");
    if (nbr < 0)
    {
        isNeg = 1;
        len++;
        nbr = -nbr;
    }
    int temp = nbr;
    while(temp)
    {
        temp /= 10;
        len++;
    }
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    result[len] = '\0';
    if (isNeg)
        result[0] = '-';
    while (nbr)
    {   
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

int main()
{
    char *nbr = ft_itoa(123);
    return (0);
}