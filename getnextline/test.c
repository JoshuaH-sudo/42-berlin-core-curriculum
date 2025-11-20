#include "src/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("src/test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    get_next_line(fd);
    close(fd);
    return (0);
}