/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:10:53 by dowon             #+#    #+#             */
/*   Updated: 2023/04/28 17:30:12 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_printf/include/ft_printf.h"
#include <signal.h>

void	mt_kill(pid_t pid, int signo)
{
	usleep(30);
	if (kill(pid, signo) == -1)
	{
		ft_putstr_fd("Failed to send signal. pid : ", STDOUT_FILENO);
		ft_putnbr_fd(pid, STDOUT_FILENO);
		ft_putstr_fd(" signal : ", STDOUT_FILENO);
		ft_putnbr_fd(signo, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit(1);
	}
}
