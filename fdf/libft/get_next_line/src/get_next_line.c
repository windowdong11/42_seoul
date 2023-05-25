/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:31 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 16:08:35 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

t_gnl_fd	*insert_gnl_fd(t_gnl_fd *prev_node, int fd)
{
	t_gnl_fd*const	new_node = malloc(sizeof(t_gnl_fd));

	new_node->fd = fd;
	new_node->len = 0;
	new_node->back = prev_node;
	new_node->front = prev_node->front;
	if (prev_node->front != NULL)
		prev_node->front->back = new_node;
	prev_node->front = new_node;
	return (new_node);
}

t_gnl_fd	*find_fd(t_gnl_fd *fd_lst, int fd)
{
	while (fd_lst->front != NULL && fd >= fd_lst->front->fd)
		fd_lst = fd_lst->front;
	if (fd_lst->fd == fd)
		return (fd_lst);
	insert_gnl_fd(fd_lst, fd);
	return (fd_lst->front);
}

char	*free_gnl_fd(t_gnl_fd *gnl_fd)
{
	t_gnl_fd	*tmp;

	while (gnl_fd)
	{
		tmp = gnl_fd;
		free(tmp);
		gnl_fd = gnl_fd->front;
	}
	return (NULL);
}

char	*read_until_endl(t_gnl_fd *gnl_fd)
{
	char	*str;
	size_t	total_length;
	size_t	prev_len;

	str = NULL;
	total_length = 0;
	while (1)
	{
		if (gnl_fd->len == 0)
			gnl_fd->len = read(gnl_fd->fd, gnl_fd->buffer, BUFFER_SIZE);
		if ((ssize_t)gnl_fd->len == -1)
		{
			free(str);
			return (NULL);
		}
		if (gnl_fd->len == 0)
			return (gnl_strcat(str, gnl_fd, total_length));
		prev_len = gnl_fd->len;
		str = gnl_strcat(str, gnl_fd, total_length);
		total_length += prev_len - gnl_fd->len;
		if (str[total_length - 1] == '\n')
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_gnl_fd	dummy_fd = {-1, "", 0, NULL, NULL};
	t_gnl_fd		*gnl_fd;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl_fd = find_fd(&dummy_fd, fd);
	result = read_until_endl(gnl_fd);
	if (result == NULL)
	{
		if (gnl_fd->back != NULL)
			gnl_fd->back->front = gnl_fd->front;
		if (gnl_fd->front != NULL)
			gnl_fd->front->back = gnl_fd->back;
		free(gnl_fd);
		return (NULL);
	}
	return (result);
}
