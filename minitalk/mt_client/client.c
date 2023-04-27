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
	if (g_conn.status != stat_data)
	{
		ft_printf("[Error] status is not data!\n");
		exit(1);
	}
	g_conn.last_bit = g_conn.message[g_conn.message_idx] >> g_conn.bit_idx & 1;
	if (g_conn.bit_idx == 0)
	{
		g_conn.bit_idx = (sizeof(char) << 3) - 1;
		g_conn.message_idx++;
	}
	else
		--g_conn.bit_idx;
	g_conn.status = stat_data_w;
	if (g_conn.last_bit)
		mt_kill(g_conn.pid, SIGNAL_1, 1);
	else
		mt_kill(g_conn.pid, SIGNAL_0, 1);
}

void	sendMsg()
{
	if (g_conn.status != stat_msg)
	{
		ft_printf("Error in sendMsg. stat is not msg\n");
		return ;
	}
	if (g_conn.message[g_conn.message_idx] == '\0')
	{
		g_conn.status = stat_end_w;
		mt_kill(g_conn.pid, CONN_DISCONNECT, 1);
	}
	else
	{
		g_conn.status = stat_msg_w;
		mt_kill(g_conn.pid, CONN_MSG, 1);
	}
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid != g_conn.pid)
		return ;
	if (g_conn.status == stat_conn_w)
	{
		if (signo == SIGNAL_1)
			g_conn.status = stat_msg;
		else
			g_conn.status = stat_conn;
	}
	else if (g_conn.status == stat_msg_w)
	{
		if (signo == CONN_MSG)
			g_conn.status = stat_data;
		else
		{
			ft_putstr_fd("Retry in msg_w\n", STDOUT_FILENO);
			g_conn.status = stat_conn;
		}
	}
	else if (g_conn.status == stat_data_w)
	{
		if (signo == SIGNAL_1)
			g_conn.status = stat_msg;
		else
		{
			ft_putstr_fd("Retry in data_w\n", STDOUT_FILENO);
			g_conn.status = stat_data_w;
		}
	}
	else if (g_conn.status == stat_end_w)
	{
		if (signo == SIGNAL_1)
		{
			ft_putstr_fd("End connection.\n", STDOUT_FILENO);
			g_conn.status = stat_end;
		}
		else
		{
			ft_putstr_fd("Error in end_w\n", STDOUT_FILENO);
			g_conn.status = stat_end;
		}
	}
}

void startConnection()
{
	g_conn.status = stat_conn_w;
	ft_putstr_fd("[Request] Send start signal\n", STDOUT_FILENO);
	mt_kill(g_conn.pid, CONN_CONNECT, 1);
}

int main(int argc, char *argv[])
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [server PID] [message]\n");
		return (0);
	}
	ft_printf("Client PID: %d\n", getpid());
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
	while (!(g_conn.status == stat_end || g_conn.status == stat_end_w))
	{
		while (g_conn.status == stat_conn || g_conn.status == stat_conn_w)
		{
			startConnection();
			usleep(100);
			if (g_conn.status == stat_conn)
			{
				ft_putstr_fd("Rejected. Retry connection.\n", STDOUT_FILENO);
				usleep(30000);
			}
		}
		sendMsg();
		while (!(g_conn.status == stat_end || g_conn.status == stat_end_w))
		{
			if (g_conn.status == stat_msg_w)
				pause();
			sendBit();
			if (g_conn.status == stat_data_w)
				pause();
			sendMsg();
		}
		ft_putstr_fd("Wait for end connection.\n", STDOUT_FILENO);
		if (g_conn.status == stat_end_w)
			pause();
	}
	return (0);
}
