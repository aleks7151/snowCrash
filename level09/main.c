#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <ctype.h>

int main(int argc, char **argv)
{
        char buf[512];
		bzero(buf, 512);
        int fd = open(argv[1], O_RDONLY);
		size_t size = read(fd, &buf, 512);
        for (int i = 0; i < size; i++)
                if (!isspace(buf[i]))
                        buf[i] = buf[i] - (char)i;
        puts(buf);
        return(0);
}
