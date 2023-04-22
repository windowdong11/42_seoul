#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../common.h"
#include <signal.h>

void printBit(char bit)
{
	ft_printf("%d", bit);
}

void sendBit(int pid, char bit)
{
	printBit(bit);
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(10);
}

void charToBinaryIterToPID(char c, int pid, void (*map)(int, char))
{
	int i;

	i = sizeof(char) * 8 - 1;
	while (i >= 0)
	{
		map(pid, (c >> i) & 1);
		i--;
	}
}

void sendMessage(int pid, char *message)
{
	ft_printf("Sending message to server with PID %d\n", pid);
	ft_printf("Message: %s\n", message);
	while (*message)
	{
		charToBinaryIterToPID(*message, pid, sendBit);
		ft_printf("send: %c\n", *message);
		message++;
	}
}

int main(int argc, char *argv[])
{
	t_connection_status status;
	if (argc != 3)
	{
		ft_printf("Usage: ./client [server PID] [message]\n");
		return (0);
	}
	ft_printf("Client PID: %d\n", getpid());
	status = stat_wait
	sendMessage(ft_atoi(argv[1]), argv[2]);
	return (0);
}