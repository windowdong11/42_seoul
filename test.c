#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void	test(char **buff)
{
	buff[0][0] = '\0';
}

void	ok(char buff[][10])
{
	buff[0][0] = '\0';
}

int main()
{
	char buff[2][10];
	test((char **)buff);
	ok(buff);
	return (0);
}
