#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t p;
	p = fork(); // 1
	if (p != 0)
		printf("parent : %d\n", p);
	else
		printf("CHILD 1\n");

	p = fork(); // 2
	if (p != 0)
		printf("parent : %d\n", p);
	else
		printf("CHILD 2\n");

	p = fork(); // 3
	if (p != 0)
		printf("parent : %d\n", p);
	else
		printf("CHILD 3\n");
	// printf("common : %d\n", p);
	return 0;
}