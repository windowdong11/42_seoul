#ifndef COMMON_H
# define COMMON_H
# include "./libft/libft.h"
# define SIGNAL_OK SIGUSR2
# define SIGNAL_FAIL SIGUSR1
# define SIGNAL_0 SIGUSR1
# define SIGNAL_1 SIGUSR2
# define CONN_CONNECT SIGNAL_1
# define CONN_START SIGNAL_1
# define CONN_DATA SIGNAL_1
# define CONN_DISCONNECT SIGNAL_0
# define CONN_RETRY SIGNAL_0

typedef enum e_connection_status
{
	stat_conn,
	stat_wait,
	stat_msg,
	stat_data,
	stat_end,
	stat_verify
}	t_connection_status;

typedef struct s_connections
{
	t_list				*lst;
	char				buffer;
	char				length;
	t_connection_status	status;
}	t_connections;

#endif