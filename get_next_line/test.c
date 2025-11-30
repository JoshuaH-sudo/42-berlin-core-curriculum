#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
    char *str;
    int fd;

    // // Test 1: Negative fd
    // printf("Test 1: Negative fd\n");
    // str = get_next_line(-1);
    // printf("Result: %s\n\n", str ? str : "NULL");

    // // Test 2: Invalid fd number
    // printf("Test 2: Invalid fd (9999)\n");
    // str = get_next_line(9999);
    // printf("Result: %s\n\n", str ? str : "NULL");

    // // Test 3: Closed fd
    // printf("Test 3: Closed fd\n");
    // fd = open("test.txt", O_RDONLY);
    // close(fd);
    // str = get_next_line(fd);
    // printf("Result: %s\n\n", str ? str : "NULL");

    // // Test 4: Write-only fd
    // printf("Test 4: Write-only fd\n");
    // fd = open("test.txt", O_WRONLY);
    // str = get_next_line(fd);
    // printf("Result: %s\n\n", str ? str : "NULL");
    // if (fd >= 0)
    //     close(fd);

    // Normal test
    printf("Test 5: Valid fd\n");
    fd = open("multiple_nl.txt", O_RDONLY);
	char *str2;
    int fd2 = open("test.txt", O_RDONLY);
	int counter = 1;
	int counter2 = 1;
	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
    if (fd < 0)
        return (1);
    while (str)
    {
        str = get_next_line(fd);
		str2 = get_next_line(fd2);
		if (str)
		{
        	printf("str1: line %d found: %s\n", counter++, str);
			free(str);
		}
		if (str2)
		{
        	printf("str2: line %d found: %s\n", counter2++, str2);
        	free(str2);
		}
    }
	printf("\n--done--\n");
    close(fd);
    close(fd2);
    return (0);
}