#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int     fd;
	char    *line;

	//fd = open("test.txt", O_RDONLY);
	//fd = open("multiple_nl.txt", O_RDONLY);
	fd = open("single_line_no_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	int counter = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %d: %s", counter++, line);
		free(line);
	}
	close(fd);
	return (0);
}