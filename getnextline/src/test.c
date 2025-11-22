#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    // while (1)
    // {
        char *str = get_next_line(fd);
        printf("line0: %s\n", str);
        char *str1 = get_next_line(fd);
        printf("line1: %s\n", str1);
        char *str2 = get_next_line(fd);
        printf("line2: %s\n", str2);
    // }
    close(fd);
    return (0);
}