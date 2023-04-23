#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../common.h"
#include <signal.h>

t_client_info	g_conn;

void printBit(char bit)
{
	ft_printf("%d", bit);
}

char	signal_to_bit(int signal)
{
	if (signal == SIGUSR1)
		return (0);
	else if (signal == SIGUSR2)
		return (1);
	return (-1);
}

void sendBit()
{
	g_conn.last_bit = g_conn.message[g_conn.message_idx] >> g_conn.bit_idx & 1;
	if (g_conn.bit_idx == 0)
		g_conn.bit_idx = (sizeof(char) << 3) - 1;
	else
		--g_conn.bit_idx;
	if (g_conn.last_bit)
		kill(g_conn.pid, SIGNAL_1);
	else
		kill(g_conn.pid, SIGNAL_0);
}

void	sendMsg()
{
	if (g_conn.message[g_conn.message_idx] == '\0')
	{
		g_conn.status = stat_end;
		kill(g_conn.pid, CONN_DISCONNECT);
	}
	else
	{
		g_conn.status = stat_msg;
		kill(g_conn.pid, CONN_MSG);
	}
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (signo == SIGUSR1)
		ft_printf("[SIGUSR1]\n");
	else
		ft_printf("[SIGUSR2]\n");
	ft_printf("%d\n", g_conn.status);
	ft_printf("%d\n", info->si_pid);
	if (info->si_pid != g_conn.pid)
		return ;
	if (g_conn.status == stat_conn)
	{
		ft_printf("[Response] Received connection signal\n");
		if (signo == CONN_WAIT)
		{
			ft_printf("Waiting for start msg signal.....\n");
			g_conn.status = stat_wait;
		}
		else
		{
			ft_printf("[Request (Retry)] Send start signal\n");
			kill(g_conn.pid, CONN_CONNECT);
		}
	}
	else if (g_conn.status == stat_wait)
	{
		ft_printf("[Response] Received wait signal\n");
		if (signo == CONN_MSG)
		{
			ft_printf("[Response] Received start msg signal\n");
			sendMsg();
		}
		else
		{
			ft_printf("[Error] When waiting for start msg signal.\n");
			kill(g_conn.pid, CONN_DISCONNECT);
		}
	}
	else if (g_conn.status == stat_msg)
	{
		ft_printf("[Response] Received msg signal\n");
		if (signo == CONN_MSG)
		{
			ft_printf("Server handled msg signal.\n");
			g_conn.status = stat_data;
			sendBit();
		}
		else
		{
		}
	}
	else if (g_conn.status == stat_data)
	{
		ft_printf("[Response] Received verify data signal\n");
		if (signo ^ g_conn.last_bit)
			kill(g_conn.pid, VERIFY_FAIL);
		else
			kill(g_conn.pid, VERIFY_OK);
		g_conn.status = stat_verify;
	}
	else if (g_conn.status == stat_verify)
	{
		ft_printf("[Response] Received connection signal\n");
		if (signo == SIGNAL_OK)
		{
			kill(g_conn.pid, SIGNAL_OK);
			g_conn.status = stat_msg;
		}
		else
			sendBit();
	}
	else if (g_conn.status == stat_end)
	{
		if (signo == CONN_DISCONNECT)
			ft_printf("[Response] Received end signal\n");
		else
			ft_printf("[Error] Error on receiving disconnect signal.\n");
		exit(0);
	}
}

void startConnection(int pid, char *message)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_usr;
	sigemptyset(&sa.sa_mask);
	sa.sa_mask = SIGUSR1 | SIGUSR2;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("[Error] Error to set signal handler in sigaction.\n");
		return ;
	}
	g_conn.bit_idx = (sizeof(char) << 3) - 1;
	g_conn.message_idx = 0;
	g_conn.message = message;
	g_conn.status = stat_conn;
	g_conn.pid = pid;
	kill(pid, CONN_CONNECT);
	ft_printf("[Request] Send start signal\n");
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client [server PID] [message]\n");
		return (0);
	}
	ft_printf("Client PID: %d\n", getpid());
	while (1)
	{
		startConnection(ft_atoi(argv[1]), argv[2]);
		usleep(30000);
	}
	while (1)
		pause();
	return (0);
}
