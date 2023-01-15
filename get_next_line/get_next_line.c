/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:12:31 by dowon             #+#    #+#             */
/*   Updated: 2023/01/11 06:34:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.h"
#include <unistd.h>

static char	*gnl_lst_cat(const t_gnl_str *begin, t_gnl_str *end, char *str_end)
{
	const t_gnl_str*const	start = begin;
	char					*str;
	size_t					str_len;

	str_len = 0;
	while (begin != end)
	{
		str_len += ft_strlen(begin->prev);
		begin = begin->front;
	}
	str_len += str_end - end->prev + 1;
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	begin = start;
	while (begin != end)
	{
		ft_strcat_until_end(str, begin->prev, str_end);
		begin = begin->front;
	}
	ft_strcat_until_end(str, begin->prev, str_end);
	return (str);
}

static t_gnl_str	*gnl_append_str(t_gnl_fd *lst)
{
	t_gnl_str*const	new_node = malloc(sizeof(t_gnl_str));

	if (new_node == NULL)
		return (NULL);
	new_node->str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new_node->cur = new_node->str;
	new_node->prev = new_node->str;
	if (new_node->str == NULL)
		return (NULL);
	new_node->str[0] = '\0';
	new_node->front = NULL;
	if (lst->buffer == NULL)
	{
		lst->buffer = new_node;
		lst->cur = new_node;
		return (new_node);
	}
	lst->cur->front = new_node;
	return (new_node);
}

static t_gnl_fd	*gnl_append_fd(t_gnl_fd *lst, int fd)
{
	t_gnl_fd*const	new_node = (t_gnl_fd *)malloc(sizeof(t_gnl_fd));

	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->buffer = NULL;
	new_node->status = reading;
	gnl_append_str(new_node);
	if (new_node->buffer == NULL)
		return (NULL);
	new_node->front = lst->front;
	new_node->back = lst;
	lst->front->back = new_node;
	lst->front = new_node;
	return (lst->front);
}

void	gnl_clear_buffer(t_gnl_fd *lst)
{
	t_gnl_str	*tmp;

	while (lst->buffer != lst->cur)
	{
		tmp = lst->buffer;
		lst->buffer = lst->buffer->front;
		free(tmp->str);
		free(tmp);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_fd	lst = {-1, NULL, NULL, &lst, &lst};
	t_gnl_fd		*cur_lst;
	t_gnl_str		*tmp_str;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cur_lst = lst.front;
	// 1. part 1 - move list to fd
	// search for fd
	while (cur_lst != &lst && cur_lst->fd != fd)
		cur_lst = cur_lst->front;
	// add new fd_node if not exists
	if (cur_lst->fd != fd)
	{
		cur_lst = gnl_append_fd(cur_lst, fd);
		if (cur_lst == NULL)
			return (NULL);
		cur_lst->cur->len = read(fd, cur_lst->cur->str, BUFFER_SIZE);
		if (cur_lst->cur->len <= 0)
			cur_lst->cur->cur[0] = '\0';
	}
	// 2. part 2 - find end line
	cur_lst->cur->cur = ft_strlchr(cur_lst->cur->prev, '\n', cur_lst->cur->len);
	while (cur_lst->cur->front != NULL && *cur_lst->cur->cur != '\n')
	{
		cur_lst->cur = cur_lst->cur->front;
		cur_lst->cur->cur = ft_strlchr(cur_lst->cur->prev, '\n', cur_lst->cur->len);
	}
	// read file if not exists
	while (*cur_lst->cur->cur != '\n')
	{
		cur_lst->cur = gnl_append_str(cur_lst);
		if (cur_lst->cur == NULL)
			return (NULL);
		cur_lst->cur->len = read(cur_lst->fd, cur_lst->cur->str, BUFFER_SIZE);
		if (cur_lst->cur->len <= 0)
		{
			cur_lst->cur->cur[0] = '\0';
			break ;
		}
		cur_lst->cur->str[cur_lst->cur->len] = '\0';
		cur_lst->cur->cur = ft_strlchr(cur_lst->cur->str, '\n', cur_lst->cur->len);
		cur_lst->cur = cur_lst->cur->front;
	}
	// 3. part 3 - cat strings
	str = gnl_lst_cat(cur_lst->buffer, cur_lst->cur, cur_lst->cur->cur);
	cur_lst->cur->prev = cur_lst->cur->cur + 1;
	while (cur_lst->buffer != NULL
		&& cur_lst->buffer->str + cur_lst->buffer->len <= cur_lst->cur->cur)
	{
		tmp_str = cur_lst->buffer;
		cur_lst->buffer = cur_lst->buffer->front;
		if (cur_lst->buffer == cur_lst->cur)
			cur_lst->cur = cur_lst->buffer;
		free(tmp_str->str);
		free(tmp_str);
	}
	return (str);
}
