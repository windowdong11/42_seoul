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
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_mask = SIGUSR1 | SIGUSR2;
	sa.sa_sigaction = sig_usr;
	sigaction(SIGUSR1, &sa, NULL);
	printf("pid : %d\n", getpid());
	printf("Running\n");
	usleep(10000000);
	printf("Continue\n");
	pause();
	return 0;
}