/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:31 by dowon             #+#    #+#             */
/*   Updated: 2023/01/28 17:46:38 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.h"

void	*clear_gnl_fd(t_gnl_fd *t_gnl_fd)
{
	t_gnl_str *tmp;

	while (t_gnl_fd->buffer != NULL)
	{
		tmp = t_gnl_fd->buffer;
		t_gnl_fd->buffer = t_gnl_fd->buffer->front;
		free(tmp);
	}
	t_gnl_fd->front->back = t_gnl_fd->back;
	if (t_gnl_fd->back)
		t_gnl_fd->back->front = t_gnl_fd->front;
	free(t_gnl_fd);
	return (NULL);
}

t_gnl_str	*new_gnl_str(t_gnl_fd *gnl_fd)
{
	t_gnl_str*const	gnl_str = (t_gnl_str *)malloc(sizeof(t_gnl_str));

	if (gnl_str == NULL)
		return (NULL);
	gnl_str->str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	gnl_str->str_cursor_prev = gnl_str->str ;
	gnl_str->str_cursor = gnl_str->str;
	gnl_str->front = NULL;
	if (gnl_str->str == NULL)
		return (NULL);
	gnl_str->len = read(gnl_fd->fd, gnl_str->str, BUFFER_SIZE);
	if (gnl_str->len <= 0)
	{
		free(gnl_str);
		gnl_fd->status = ended;
		return (NULL);
	}
	if (gnl_str->len == -1)
	{
		free(gnl_str);
		clear_gnl_fd(gnl_fd);
		return (NULL);
	}
	if (gnl_fd->buffer == NULL)
	{
		gnl_fd->buffer = gnl_str;
		gnl_fd->buf_cursor = gnl_str;
	}
	else
		gnl_fd->buf_cursor->front = gnl_str;
	return (gnl_str);
}

// gnl_fd->back = NULL;
t_gnl_fd	*new_gnl_fd(int fd)
{
	t_gnl_fd*const	gnl_fd = (t_gnl_fd *)malloc(sizeof(t_gnl_fd));

	if (gnl_fd == NULL)
		return (NULL);
	gnl_fd->fd = fd;
	gnl_fd->buffer = NULL;
	gnl_fd->buf_cursor = NULL;
	gnl_fd->front = NULL;
	gnl_fd->status = reading;
	return (gnl_fd);
}

/*
1. 다음 노드가 존재하거나, 다음 fd가 작거나 같을 때까지 이동
	-> 마지막 노드에서 멈춤 -> 찾는 fd와 일치하거나 더 작으면 멈춤
	7을 찾을 때,
	a) (-1) -> ... -> "(4)" -> (NULL)
		a`) "(-1)" -> (NULL)
	b) (-1) -> ... "(3)" -> (8) -> (12) -> (NULL)
	c) (-1) -> ... (3) -> "(7)" -> (12) -> (NULL)
2. fd가 일치하면, 반환 (케이스 c)
3. 다음 노드에 추가 & 반환 (케이스 a, b)
*/
t_gnl_fd	*find_fd(t_gnl_fd *fd_lst, int fd)
{
	while (fd_lst->front != NULL && fd >= fd_lst->front->fd)
		fd_lst = fd_lst->front;
	if (fd_lst->fd == fd)
		return (fd_lst);
	fd_lst->front = new_gnl_fd(fd);
	return (fd_lst->front);
}

void	read_file(t_gnl_fd *gnl_fd)
{
	const char	*str_end;

	if (gnl_fd->buf_cursor == NULL)
	{
		if (new_gnl_str(gnl_fd) == NULL)
			return ;
	}
	while (gnl_fd->buf_cursor != NULL)
	{
		str_end = gnl_fd->buf_cursor->str + gnl_fd->buf_cursor->len - 1;
		gnl_fd->buf_cursor->str_cursor_prev = gnl_fd->buf_cursor->str_cursor;
		while (gnl_fd->buf_cursor->str_cursor < str_end
			&& *gnl_fd->buf_cursor->str_cursor != '\n')
			gnl_fd->buf_cursor->str_cursor++;
		if (*gnl_fd->buf_cursor->str_cursor == '\n')
			return ;
		if (new_gnl_str(gnl_fd) == NULL)
			return ;
		gnl_fd->buf_cursor = gnl_fd->buf_cursor->front;
	}
}

char	*parse_line(t_gnl_fd *gnl_fd)
{
	t_gnl_str	*current;
	size_t		len;
	char		*str;
	char		*str_origin;

	current = gnl_fd->buffer;
	if (current == NULL)
		return (NULL);
	len = 0;
	while (current != NULL)
	{
		len += current->str_cursor - current->str_cursor_prev + 1;
		if (current->str_cursor < current->str + current->len - 1)
			break ;
		current = current->front;
	}
	str_origin = (char *)malloc(sizeof(char) * (len + 1));
	if (str_origin == NULL)
		return (NULL);
	str = str_origin;
	current = gnl_fd->buffer;
	while (current != NULL)
	{
		while (current->str_cursor_prev <= current->str_cursor)
			*str++ = *current->str_cursor_prev++;
		if (current->str_cursor < current->str + current->len - 1)
		{
			current->str_cursor = current->str_cursor + 1;
			break ;
		}
		free(current->str);
		gnl_fd->buffer = gnl_fd->buffer->front;
		free(current);
		current = gnl_fd->buffer;
	}
	gnl_fd->buf_cursor = gnl_fd->buffer;
	*str = '\0';
	return (str_origin);
}

/*
done 1. find fd (없으면 추가해서 반환해줌)
todo 2. find endl
todo 	2-1. if cursor moved -> parse and return
todo 3. read
todo 	3-1. read buffer size
todo 	3-2. check eof 
todo 			if buffer is empty
todo 				return NULL;
todo 			else 
todo 				return join(...);
todo 	3-3. check endl
todo 		clear_buffer_to_cursor();
todo 		return join(...);
todo 	3-4. goto 3-1
*/
char	*get_next_line(int fd)
{
	static t_gnl_fd	fd_lst = {-1, NULL, NULL, NULL, NULL, ended};
	t_gnl_fd		*gnl_fd;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl_fd = find_fd(&fd_lst, fd);
	if (gnl_fd == NULL || gnl_fd->fd < 0)
		return (NULL);
	read_file(gnl_fd);
	if (find_fd(&fd_lst, fd) == NULL)
		return (NULL);
	line = parse_line(gnl_fd);
	return (line);
}