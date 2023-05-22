/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:35 by dowon             #+#    #+#             */
/*   Updated: 2023/02/08 17:10:03 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_gnl_fd
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	size_t			len;
	struct s_gnl_fd	*front;
	struct s_gnl_fd	*back;
}	t_gnl_fd;

t_gnl_fd	*insert_gnl_fd(t_gnl_fd *prev_node, int fd);
t_gnl_fd	*find_fd(t_gnl_fd *fd_lst, int fd);
char		*free_gnl_fd(t_gnl_fd *gnl_fd);
char		*read_until_endl(t_gnl_fd *gnl_fd);
char		*get_next_line(int fd);
char		*gnl_strcat(char *src, t_gnl_fd *gnl_fd, size_t src_len);

#endif