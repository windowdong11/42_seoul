#ifndef COMMON_H
# define COMMON_H
# include "./libft/libft.h"
# define SIGNAL_OK SIGUSR2
# define SIGNAL_FAIL SIGUSR1
# define SIGNAL_0 SIGUSR1
# define SIGNAL_1 SIGUSR2
# define CONN_CONNECT SIGNAL_1
# define CONN_WAIT SIGNAL_1
# define CONN_MSG SIGNAL_1
# define CONN_DATA SIGNAL_1
# define CONN_DISCONNECT	SIGNAL_0
# define CONN_RETRY			SIGNAL_0
# define VERIFY_OK			SIGNAL_1
# define VERIFY_FAIL		SIGNAL_0

typedef enum e_connection_status
{
	stat_wait,
	stat_wait_w,
	stat_conn,
	stat_conn_w,
	stat_msg,
	stat_msg_w,
	stat_data,
	stat_data_w,
	stat_end,
	stat_end_w
}	t_connection_status;

typedef struct s_client_info
{
	int					pid;
	char				last_bit;
	size_t				message_idx;
	char				bit_idx;
	char				*message;
	t_connection_status	status;
}	t_client_info;

typedef struct s_server_info
{
	t_list				*lst;
	pid_t				pid;
	char				buffer;
	char				length;
	t_connection_status	status;
}	t_server_info;

int	mt_kill(pid_t pid, int signo, int print);

#endif