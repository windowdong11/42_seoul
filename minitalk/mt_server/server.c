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

int	mt_kill(pid_t pid, int signo)
{
	ft_printf("[Send] to %d ", pid);
	if (signo == SIGUSR1)
		ft_printf("[SIGUSR1]\n");
	else
		ft_printf("[SIGUSR2]\n");
	return (kill(pid, signo));
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
	int	pid;

	pid = get_active_pid();
	mt_kill(pid, CONN_DISCONNECT);
	ft_lstpop_front(&g_conn.lst, free);
	pid = get_active_pid();
	if (pid != -1)
	{
		mt_kill(pid, CONN_CONNECT);
		g_conn.length = 0;
		g_conn.buffer = 0;
		g_conn.status = stat_wait;
	}
	else
		g_conn.status = stat_conn;
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	ft_printf("[Recv] from %d ", info->si_pid);
	if (signo == SIGUSR1)
		ft_printf("[SIGUSR1]\n");
	else
		ft_printf("[SIGUSR2]\n");
	if (get_active_pid() != info->si_pid)
	{
		if (signo == SIGNAL_0)
			mt_kill(info->si_pid, SIGNAL_FAIL);
		else if (signo == SIGNAL_1)
		{
			if (push_connection(info->si_pid) == NULL)
				mt_kill(info->si_pid, CONN_RETRY);
			else
			{
				mt_kill(info->si_pid, CONN_MSG);
				g_conn.status = stat_msg;
			}
		}
	}
	else if (g_conn.status == stat_wait)
	{
		if (signo == SIGNAL_0)
			mt_kill(info->si_pid, CONN_RETRY);
		else if (signo == SIGNAL_1)
		{
			g_conn.status = stat_msg;
			mt_kill(info->si_pid, CONN_MSG);
		}
	}
	// else if (g_conn.status == stat_msg)
	// {
	// 	if (signo == SIGNAL_0)
	// 		end_connection();
	// 	else if (signo == SIGNAL_1)
	// 	{
	// 		mt_kill(info->si_pid, SIGNAL_1);
	// 		g_conn.status = stat_data;
	// 	}
	// }
	// else if (g_conn.status == stat_data)
	// {
	// 	g_conn.buffer = (g_conn.buffer << 1) + (signo & 1);
	// 	g_conn.length++;
	// 	if (g_conn.length == 8)
	// 	{
	// 		ft_putchar_fd(g_conn.buffer, STDOUT_FILENO);
	// 		g_conn.buffer = 0;
	// 		g_conn.length = 0;
	// 	}
	// 	g_conn.status = stat_verify;
	// }
	// else if (g_conn.status == stat_verify)
	// {
	// 	if (signo == SIGNAL_FAIL)
	// 	{
	// 		g_conn.buffer >>= 1;
	// 		g_conn.status = stat_data;
	// 		mt_kill(info->si_pid, SIGNAL_FAIL);
	// 	}
	// 	else if (signo == SIGNAL_OK)
	// 	{
	// 		g_conn.status = stat_msg;
	// 		mt_kill(info->si_pid, SIGNAL_OK);
	// 	}
	// }
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
	g_conn.status = stat_conn;
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
