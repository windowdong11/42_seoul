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

t_connections	g_conn;

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
	int	pid;

	pid = get_active_pid();
	kill(pid, CONN_DISCONNECT);
	ft_lstpop_front(&g_conn.lst, free);
	pid = get_active_pid();
	if (pid != -1)
	{
		kill(pid, CONN_START);
		g_conn.length = 0;
		g_conn.buffer = 0;
		g_conn.status = stat_wait;
	}
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (get_active_pid() != info->si_pid)
	{
		if (signo == SIGNAL_0)
			kill(info->si_pid, SIGNAL_FAIL);
		else if (signo == SIGNAL_1)
		{
			if (push_connection(info->si_pid) == NULL)
				kill(info->si_pid, CONN_RETRY);
			else
				kill(info->si_pid, CONN_CONNECT);
		}
	}
	else if (g_conn.status == stat_wait)
	{
		if (signo == SIGNAL_0)
			kill(info->si_pid, CONN_RETRY);
		else if (signo == SIGNAL_1)
		{
			g_conn.status = stat_msg;
			kill(info->si_pid, CONN_DATA);
		}
	}
	else if (g_conn.status == stat_msg)
	{
		if (signo == SIGNAL_0)
			end_connection();
		else if (signo == SIGNAL_1)
		{
			kill(info->si_pid, SIGNAL_1);
			g_conn.status = stat_data;
		}
	}
	else if (g_conn.status == stat_data)
	{
		// TODO : VERIFY DATA
		g_conn.buffer = (g_conn.buffer << 1) + (signo & 1);
		g_conn.length++;
		if (g_conn.length == 8)
		{
			ft_printf("%c", g_conn.buffer);
			g_conn.buffer = 0;
			g_conn.length = 0;
		}
		g_conn.status = stat_verify;
	}
	else if (g_conn.status == stat_verify)
	{
		g_conn.status = stat_wait;
	}
}

int	main(void)
{
	struct sigaction	usrsig;

	usrsig.sa_sigaction = sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_mask = SIGUSR1;
	usrsig.sa_mask = SIGUSR2;
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
	g_conn.status = stat_wait;
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		usleep(10000000);
		pause();
	}
	return (0);
}
