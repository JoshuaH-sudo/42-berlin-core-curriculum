#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		char *str = get_next_line(fd);
		// char *str = get_next_line(1); // to read from standard input
		if (!str)
			break ;
		printf("line-found: %s", str);
	}
	close(fd);
	return (0);
}