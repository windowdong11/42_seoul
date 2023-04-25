/*
write
◦ ft_printf and any equivalent YOU coded
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit
*/

#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../common.h"
#include <stdarg.h>
#include <signal.h>

t_server_info	g_conn;

void printConn()
{
	ft_printf("pid : %d, buff : %d, len : %d, stat : %d\n", g_conn.pid, g_conn.buffer, g_conn.length, g_conn.status);
}

t_list	*push_connection(int pid)
{
	int*const		new_content = malloc(sizeof(int));
	t_list*const	new_node = ft_lstnew(NULL);

	if (new_content == NULL || new_node == NULL)
	{
		free(new_content);
		free(new_node);
		return (NULL);
	}
	*new_content = pid;
	new_node->content = new_content;
	ft_lstadd_back(&g_conn.lst, new_node);
	return (new_node);
}

int	get_active_pid(void)
{
	if (g_conn.lst == NULL)
		return (-1);
	return (*(int *)g_conn.lst->content);
}

void	end_connection()
{
	const pid_t	pid = g_conn.pid;

	g_conn.length = 0;
	g_conn.buffer = 0;
	g_conn.pid = -1;
	g_conn.status = stat_end;
	ft_printf("End connection\n");
	printConn();
	kill(pid, SIGNAL_1);
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	ft_printf("recv");
	if (g_conn.status == stat_wait)
	{
		g_conn.pid = info->si_pid;
		g_conn.status = stat_msg_w;
		ft_printf("Connection Requested\n");
	}
	else if (g_conn.pid != info->si_pid)
	{
		ft_printf("\n[Reject] pid : %d\n", info->si_pid);
		mt_kill(info->si_pid, SIGNAL_0, 1);
	}
	else if (g_conn.status == stat_msg_w)
	{
		if (signo & 1)
			g_conn.status = stat_data_w;
		else
			end_connection();
	}
	else if (g_conn.status == stat_data_w)
	{
		g_conn.buffer = (g_conn.buffer << 1) + (signo & 1);
		g_conn.length++;
		if (g_conn.length == 8)
		{
			ft_putchar_fd(g_conn.buffer, STDOUT_FILENO);
			g_conn.buffer = 0;
			g_conn.length = 0;
		}
		g_conn.status = stat_msg_w;
	}
}

int	main(void)
{
	struct sigaction	usrsig;

	usrsig.sa_sigaction = sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_mask = SIGUSR1 | SIGUSR2;
	usrsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &usrsig, 0) == -1)
	{
		ft_printf("signal(SIGUSR1) error");
		return (-1);
	}
	if (sigaction(SIGUSR2, &usrsig, 0) == -1)
	{
		ft_printf("signal(SIGUSR2) error");
		return (-1);
	}
	g_conn.lst = NULL;
	g_conn.buffer = 0;
	g_conn.length = 0;
	g_conn.pid = -1;
	g_conn.status = stat_wait;
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		g_conn.status = stat_wait;
		while (g_conn.status == stat_wait)
			pause();
		// req message
		mt_kill(g_conn.pid, SIGNAL_1, 0);
		// get message
		if (g_conn.status == stat_msg_w)
			pause();
		while (g_conn.status != stat_end)
		{
			// req data
			mt_kill(g_conn.pid, SIGNAL_1, 0);
			// get data
			if (g_conn.status == stat_data_w)
				pause();
			// req message
			mt_kill(g_conn.pid, SIGNAL_1, 0);
			// get message
			if (g_conn.status == stat_msg_w)
				pause();
		}
	}
	return (0);
}
