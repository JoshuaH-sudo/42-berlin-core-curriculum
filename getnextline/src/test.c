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
		printf("Returned line address: %p\n", str);
		if (!str)
			break ;
		printf("line-found: %s\n", str);
	}
	close(fd);
	return (0);
}