#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	run_test(char *filename)
{
	int		fd;
	char	*line;
	int		counter;

	printf("=== Testing %s ===\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return ;
	}
	counter = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %d: %s", counter++, line);
		free(line);
	}
	close(fd);
	printf("\n");
}

#define TEST_FILE(file) run_test(file)

int	main(void)
{
	printf("----- get_next_line Test Suite -----\n\n");
	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	// TEST_FILE("test.txt");
	// TEST_FILE("multiple_nl.txt");
	TEST_FILE("single_line_no_nl.txt");
	// TEST_FILE("empty.txt");
	// TEST_FILE("1char.txt");
	// TEST_FILE("long_line.txt");
	printf("----- End of Test Suite -----\n");
	return (0);
}