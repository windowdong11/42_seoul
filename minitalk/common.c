#include "common.h"
#include "ft_printf/include/ft_printf.h"
#include <signal.h>

int	mt_kill(pid_t pid, int signo, int print)
{
	if (print && 0)
	{
		ft_printf("[Send] to %d ", pid);
		if (signo == SIGUSR1)
			ft_printf("[SIGUSR1]\n");
		else
			ft_printf("[SIGUSR2]\n");
	}
	if (pid < 100)
		return (0);
	usleep(100);
	return (kill(pid, signo));
}

// void printStat(e_connection_status stat)
// {
// 	if (stat == stat_conn)
// 		ft_putstr_fd("stat: conn");
// 	else if (stat == stat)
// }