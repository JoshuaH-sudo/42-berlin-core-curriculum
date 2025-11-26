#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
    char *str;
    int fd;

    // Test 1: Negative fd
    printf("Test 1: Negative fd\n");
    str = get_next_line(-1);
    printf("Result: %s\n\n", str ? str : "NULL");

    // Test 2: Invalid fd number
    printf("Test 2: Invalid fd (9999)\n");
    str = get_next_line(9999);
    printf("Result: %s\n\n", str ? str : "NULL");

    // Test 3: Closed fd
    printf("Test 3: Closed fd\n");
    fd = open("test.txt", O_RDONLY);
    close(fd);
    str = get_next_line(fd);
    printf("Result: %s\n\n", str ? str : "NULL");

    // Test 4: Write-only fd
    printf("Test 4: Write-only fd\n");
    fd = open("test.txt", O_WRONLY);
    str = get_next_line(fd);
    printf("Result: %s\n\n", str ? str : "NULL");
    if (fd >= 0)
        close(fd);

    // Normal test
    printf("Test 5: Valid fd\n");
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while (1)
    {
        str = get_next_line(fd);
        if (!str)
            break ;
        printf("line-found: %s", str);
        free(str);
    }
    close(fd);
    return (0);
}