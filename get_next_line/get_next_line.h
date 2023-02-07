/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:35 by dowon             #+#    #+#             */
/*   Updated: 2023/01/15 03:56:39 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/*#include "get_next_line.h"*/
typedef enum e_read_status {
	reading,
	ended,
}	t_read_status;

typedef struct s_gnl_str
{
	char				*str;
	char				*str_cursor_prev;
	char				*str_cursor;
	struct s_gnl_str	*front;
	ssize_t				len;
}	t_gnl_str;

typedef struct s_gnl_fd
{
	int				fd;
	t_gnl_str		*buffer;
	t_gnl_str		*buf_cursor;
	struct s_gnl_fd	*front;
	struct s_gnl_fd	*back;
	t_read_status	status;
}	t_gnl_fd;

t_gnl_str	*new_gnl_str(t_gnl_fd *gnl_fd);
t_gnl_fd	*new_gnl_fd(int fd);
t_gnl_fd	*find_fd(t_gnl_fd *fd_lst, int fd);
void	read_file(t_gnl_fd *gnl_fd);
char	*parse_line(t_gnl_fd *gnl_fd);
char	*get_next_line(int fd);

#endif