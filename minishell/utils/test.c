#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	const char *str = "test";
	write(fd, str, 4);
	close(fd);
	return 0;
}