#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../common.h"
#include <signal.h>

t_client_info	g_conn;
int				g_verify = 1;

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
	if (g_verify == 0)
	{
		kill(g_conn.pid, g_conn.last_bit);
		return ;
	}
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
		ft_printf("[SIGUSR1] ");
	else
		ft_printf("[SIGUSR2] ");
	ft_printf("pid : %d ", info->si_pid);
	ft_printf("stat : %d\n", g_conn.status);
	if (info->si_pid != g_conn.pid)
		return ;
	if (g_conn.status == stat_conn)
	{
		ft_printf("[Response - conn] : ");
		if (signo == CONN_MSG)
		{
			ft_printf("Send msg\n");
			sendMsg();
		}
		else
			ft_printf("(Retry)\n");
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
			// retry from connection
			g_conn.status = stat_conn;
		}
	}
	// else if (g_conn.status == stat_data)
	// {
	// 	ft_printf("[Response] Received verify data signal\n");
	// 	g_verify = signo ^ g_conn.last_bit;
	// 	if (g_verify)
	// 		kill(g_conn.pid, VERIFY_FAIL);
	// 	else
	// 		kill(g_conn.pid, VERIFY_OK);
	// 	g_conn.status = stat_verify;
	// }
	// else if (g_conn.status == stat_verify)
	// {
	// 	ft_printf("[Response] Received connection signal\n");
	// 	if (signo == SIGNAL_OK)
	// 	{
	// 		kill(g_conn.pid, SIGNAL_OK);
	// 		g_conn.status = stat_msg;
	// 	}
	// 	else
	// 		sendBit();
	// }
	// else if (g_conn.status == stat_end)
	// {
	// 	if (signo == CONN_DISCONNECT)
	// 		ft_printf("[Response] Received end signal\n");
	// 	else
	// 		ft_printf("[Error] Error on receiving disconnect signal.\n");
	// 	exit(0);
	// }
}

void startConnection()
{
	kill(g_conn.pid, CONN_CONNECT);
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
	struct sigaction	sa;

	sa.sa_sigaction = sig_usr;
	sigemptyset(&sa.sa_mask);
	sa.sa_mask = SIGUSR1 | SIGUSR2;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("[Error] Error to set signal handler in sigaction.\n");
		return (-1);
	}
	g_conn.bit_idx = (sizeof(char) << 3) - 1;
	g_conn.message_idx = 0;
	g_conn.message = argv[2];
	g_conn.status = stat_conn;
	g_conn.pid = ft_atoi(argv[1]);
	while (g_conn.status != stat_end)
	{
		while (g_conn.status == stat_conn)
		{
			startConnection();
			usleep(30000);
		}
		while (1)
			pause();
	}
	return (0);
}
