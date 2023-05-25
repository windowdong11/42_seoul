#include <stdlib.h>
typedef void	(*t_destructor)(void*);
void call(t_destructor destructor, void *ptr) {
	destructor(ptr);
}

void int_destructor(int *ptr) {
	free(ptr);
}

int main() {
	int *p = malloc(sizeof(int));
	call(int_destructor, p);
	return (0);
}