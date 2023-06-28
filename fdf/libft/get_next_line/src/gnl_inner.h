/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_inner.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:10:57 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 19:17:48 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_INNER_H
# define GNL_INNER_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
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
char		*gnl_strcat(char *src, t_gnl_fd *gnl_fd, size_t src_len);

t_gnl_fd	*static_gnl_fd(void);

#endif