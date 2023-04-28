/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:11:01 by dowon             #+#    #+#             */
/*   Updated: 2023/04/28 18:24:03 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../common.h"
#include <stdarg.h>
#include <signal.h>

t_server_info	g_conn;

void	end_connection(void)
{
	const pid_t	pid = g_conn.pid;

	g_conn.length = 0;
	g_conn.buffer = 0;
	g_conn.pid = -1;
	g_conn.status = stat_end;
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putstr_fd(": End connection\n", STDOUT_FILENO);
	if (kill(pid, SIGNAL_1) == -1)
	{
		ft_putstr_fd("Failed to send [end_conn] signal. pid : ", STDOUT_FILENO);
		ft_putnbr_fd(pid, STDOUT_FILENO);
		ft_putstr_fd(" signal : ", STDOUT_FILENO);
		ft_putnbr_fd(SIGNAL_1, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

void	handle_data(int signo)
{
	g_conn.buffer = (g_conn.buffer << 1) + (signo & 1);
	g_conn.length++;
	if (g_conn.length == 8)
	{
		ft_putchar_fd(g_conn.buffer, STDOUT_FILENO);
		g_conn.buffer = 0;
		g_conn.length = 0;
	}
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid < 100)
		return ;
	if (g_conn.status == stat_wait)
	{
		g_conn.pid = info->si_pid;
		g_conn.status = stat_msg_w;
		mt_kill(g_conn.pid, SIGNAL_1);
	}
	else if (g_conn.pid != info->si_pid)
		return ;
	else if (g_conn.status == stat_msg_w)
	{
		if (signo & 1)
			g_conn.status = stat_data_w;
		else
			end_connection();
	}
	else if (g_conn.status == stat_data_w)
	{
		handle_data(signo);
		g_conn.status = stat_msg_w;
	}
}

void	start(void)
{
	g_conn.status = stat_wait;
	ft_putstr_fd("Running\n", STDOUT_FILENO);
	while (g_conn.status == stat_wait)
		pause();
	ft_putnbr_fd(g_conn.pid, STDOUT_FILENO);
	ft_putstr_fd(" : Connection Established\n", STDOUT_FILENO);
	mt_kill(g_conn.pid, SIGNAL_1);
	if (g_conn.status == stat_msg_w)
		pause();
	while (g_conn.status != stat_end)
	{
		mt_kill(g_conn.pid, SIGNAL_1);
		if (g_conn.status == stat_data_w)
			pause();
		mt_kill(g_conn.pid, SIGNAL_1);
		if (g_conn.status == stat_msg_w)
			pause();
	}
}

int	main(void)
{
	struct sigaction	usrsig;

	usrsig.sa_sigaction = sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_mask = SIGUSR1 | SIGUSR2;
	usrsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &usrsig, 0) == -1
		|| sigaction(SIGUSR2, &usrsig, 0) == -1)
	{
		ft_putstr_fd("sigaction error\n", STDOUT_FILENO);
		return (-1);
	}
	g_conn.buffer = 0;
	g_conn.length = 0;
	g_conn.pid = -1;
	g_conn.status = stat_wait;
	ft_printf("PID : %d\n", getpid());
	while (1)
		start();
	return (0);
}
