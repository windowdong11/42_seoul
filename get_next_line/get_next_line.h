/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:35 by dowon             #+#    #+#             */
/*   Updated: 2023/01/14 19:16:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>

typedef enum e_read_status {
	reading,
	ended,
}	t_read_status;

typedef struct s_gnl_str
{
	char				*str;
	char				*prev;
	char				*cur;
	struct s_gnl_str	*front;
	size_t				len;
}	t_gnl_str;

typedef struct s_gnl_fd
{
	int				fd;
	t_gnl_str		*buffer;
	t_gnl_str		*cur;
	struct s_gnl_fd	*front;
	struct s_gnl_fd	*back;
	t_read_status	status;
}	t_gnl_fd;

char	*get_next_line(int fd);

#endif