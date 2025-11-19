#include <string.h>
#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    if (!s)
        return (NULL);
    if ((start >= (unsigned int)ft_strlen(s)))
        return (ft_strdup(""));
    // The length can't be greater than the remaining string length
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    substr = (char *)malloc((len + 1) * sizeof(char));
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}