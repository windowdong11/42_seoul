#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int stat = 0;

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	stat++;
	printf("Handler Called\n");
}

int main()
{
	pid_t pid;
	printf("pid : ");
	scanf("%d", &pid);
	kill(pid, SIGUSR1);
	return 0;
}