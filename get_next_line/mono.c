#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

typedef struct s_gnl_str
{
	char *str;
	char *cur_str;
	char *prev_str;
	struct s_gnl_str *next;
	ssize_t len;
} t_gnl_str;

typedef struct s_gnl_fd
{
	int fd;
	t_gnl_str *buf;
	t_gnl_str *cur_buf;
	struct s_gnl_fd *next;
	struct s_gnl_fd *prev;
} t_gnl_fd;

t_gnl_str *append_gnl_str(t_gnl_fd *fd_node)
{
	t_gnl_str *const new_node = malloc(sizeof(t_gnl_str));
	if (new_node == NULL)
		return (delete_gnl_fd(fd_node));
	new_node->next = NULL;
	new_node->len = 0;
	new_node->str = malloc(sizeof(char) * BUFFER_SIZE);
	new_node->cur_str = new_node->str;
	new_node->prev_str = new_node->str;
	if (new_node->str == NULL)
		return (delete_gnl_fd(fd_node));
	if (fd_node->buf == NULL)
	{
		fd_node->buf = new_node;
		fd_node->cur_buf = new_node;
	}
	else
	{
		fd_node->buf->next = new_node;
		fd_node->cur_buf = fd_node->cur_buf->next;
	}
	return (new_node);
}

t_gnl_fd *insert_gnl_fd(t_gnl_fd *prev_node, int fd)
{
	t_gnl_fd *const new_node = malloc(sizeof(t_gnl_fd));
	if (new_node == NULL)
		return (NULL);
	new_node->buf = NULL;
	new_node->cur_buf = NULL;
	new_node->fd = fd;
	new_node->prev = prev_node;
	new_node->next = prev_node->next;
	if (prev_node->next != NULL)
		prev_node->next->prev = new_node;
	prev_node->next = new_node;
}

t_gnl_fd *find_fd(t_gnl_fd *fd_lst, int fd)
{
	while (fd_lst->next != NULL && fd >= fd_lst->next->fd)
		fd_lst = fd_lst->next;
	if (fd_lst->fd == fd)
		return (fd_lst);
	insert_gnl_fd(fd_lst, fd);
	return (fd_lst->next);
}

char *read_until_endl(t_gnl_fd* gnl_fd)
{
}

char *get_next_line(int fd)
{
	static t_gnl_fd dummy_fd = {-1, NULL, NULL, NULL, NULL};
	t_gnl_fd *gnl_fd;
	char *result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl_fd = find_fd(&dummy_fd, fd);
	if (gnl_fd == NULL)
		return (NULL);
	result = read_until_endl(gnl_fd);
	if (result == NULL)
		return (delete_gnl_fd(gnl_fd));
	return (result);
}