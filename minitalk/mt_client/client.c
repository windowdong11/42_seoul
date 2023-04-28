/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:22:21 by dowon             #+#    #+#             */
/*   Updated: 2023/04/28 18:41:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../common.h"
#include <signal.h>

t_client_info	g_conn;

void	send_bit(void)
{
	if (g_conn.status != stat_data)
	{
		ft_putstr_fd("[Error] status is not data!\n", STDOUT_FILENO);
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
		mt_kill(g_conn.pid, SIGNAL_1);
	else
		mt_kill(g_conn.pid, SIGNAL_0);
}

void	send_msg(void)
{
	if (g_conn.status != stat_msg)
	{
		ft_putstr_fd("[Error] status is not msg!\n", STDOUT_FILENO);
		exit(1);
	}
	if (g_conn.message[g_conn.message_idx] == '\0')
	{
		g_conn.status = stat_end_w;
		mt_kill(g_conn.pid, CONN_DISCONNECT);
	}
	else
	{
		g_conn.status = stat_msg_w;
		mt_kill(g_conn.pid, CONN_MSG);
	}
}

void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)signo;
	(void)context;
	if (info->si_pid != g_conn.pid)
		return ;
	if (g_conn.status == stat_conn_w)
		g_conn.status = stat_msg;
	else if (g_conn.status == stat_msg_w)
		g_conn.status = stat_data;
	else if (g_conn.status == stat_data_w)
		g_conn.status = stat_msg;
	else if (g_conn.status == stat_end_w)
	{
		ft_putstr_fd("End connection.\n", STDOUT_FILENO);
		g_conn.status = stat_end;
	}
}

void	start(void)
{
	ft_putstr_fd("[Request] Send start signal\n", STDOUT_FILENO);
	g_conn.status = stat_conn_w;
	mt_kill(g_conn.pid, CONN_CONNECT);
	usleep(300000);
	if (g_conn.status == stat_conn_w)
	{
		ft_putstr_fd("Timeout.\n", STDOUT_FILENO);
		exit(1);
	}
	ft_printf("stat : %d\n", g_conn.status);
	send_msg();
	while (!(g_conn.status == stat_end || g_conn.status == stat_end_w))
	{
		if (g_conn.status == stat_msg_w)
			pause();
		send_bit();
		if (g_conn.status == stat_data_w)
			pause();
		send_msg();
	}
	ft_putstr_fd("Wait for end connection.\n", STDOUT_FILENO);
	if (g_conn.status == stat_end_w)
		pause();
}

int	main(int argc, char *argv[])
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
	start();
	return (0);
}
