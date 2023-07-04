#include <stdlib.h>
#include <stdio.h>

int main()
{
	char	*result;

	result = getenv("PATH");
	printf("%s", result);
	return 0;
}