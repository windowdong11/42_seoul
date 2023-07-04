#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("sleep 10secs..\n");
	sleep(10);
	printf("woke up!");
	return 0;
}