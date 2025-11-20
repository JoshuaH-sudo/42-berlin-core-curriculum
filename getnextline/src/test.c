#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while (1)
    {
        char *str = get_next_line(fd);
        if (!str)
            break;
        printf("%s\n", str);
    }
    close(fd);
    return (0);
}