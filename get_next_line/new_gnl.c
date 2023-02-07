#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

typedef struct s_gnl_str
{
	char *str;
	char *str_cursor_prev;
	char *str_cursor;
	struct s_gnl_str *front;
	ssize_t len;
} t_gnl_str;

typedef struct s_gnl_fd
{
	int fd;
	t_gnl_str *buffer;
	t_gnl_str *buf_cursor;
	struct s_gnl_fd *front;
	struct s_gnl_fd *back;
} t_gnl_fd;

void visualize_gnl_str(t_gnl_str *gnl_str);

void *delete_gnl_fd(t_gnl_fd *fd_node)
{
	void *tmp;
	t_gnl_str *str_node = fd_node->buffer;
	while (str_node != NULL)
	{
		free(str_node->str);
		tmp = str_node;
		str_node = str_node->front;
		free(tmp);
	}
	if (fd_node->back != NULL)
	{
		fd_node->back->front = fd_node->front;
		if (fd_node->front != NULL)
			fd_node->front->back = fd_node->back;
	}
	if (fd_node->front != NULL)
	{
		fd_node->front->back = fd_node->back;
		if (fd_node->back != NULL)
			fd_node->back->front = fd_node->front;
	}
	free(fd_node);
	return (NULL);
}

void *free_all_gnl_fd(t_gnl_fd *fd_head)
{
	void *tmp;
	while (fd_head != NULL)
	{
		tmp = fd_head;
		fd_head = fd_head->front;
		delete_gnl_fd(tmp);
	}
	return (NULL);
}

t_gnl_str *append_gnl_str(t_gnl_fd *fd_node)
{
	t_gnl_str *const new_node = malloc(sizeof(t_gnl_str));
	if (new_node == NULL)
		return (delete_gnl_fd(fd_node));
	new_node->front = NULL;
	new_node->len = 0;
	new_node->str = malloc(sizeof(char) * BUFFER_SIZE);
	new_node->str_cursor = new_node->str;
	new_node->str_cursor_prev = new_node->str;
	if (new_node->str == NULL)
		return (delete_gnl_fd(fd_node));
	if (fd_node->buffer == NULL)
	{
		fd_node->buffer = new_node;
		fd_node->buf_cursor = new_node;
	}
	else
	{
		fd_node->buf_cursor->front = new_node;
		fd_node->buf_cursor = fd_node->buf_cursor->front;
	}
	return (new_node);
}

t_gnl_fd *insert_gnl_fd(t_gnl_fd *prev_node, int fd)
{
	t_gnl_fd *const new_node = malloc(sizeof(t_gnl_fd));
	if (new_node == NULL)
		return (NULL);
	new_node->buffer = NULL;
	new_node->buf_cursor = NULL;
	new_node->fd = fd;
	new_node->back = prev_node;
	new_node->front = prev_node->front;
	if (prev_node->front != NULL)
		prev_node->front->back = new_node;
	prev_node->front = new_node;
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
t_gnl_fd *find_fd(t_gnl_fd *fd_lst, int fd)
{
	while (fd_lst->front != NULL && fd >= fd_lst->front->fd)
		fd_lst = fd_lst->front;
	if (fd_lst->fd == fd)
		return (fd_lst);
	insert_gnl_fd(fd_lst, fd);
	return (fd_lst->front);
}

char *gnl_strnchr(t_gnl_str *gnl_str, char c)
{
	if (gnl_str == NULL || gnl_str->str == NULL)
		return (NULL);
	while (gnl_str->str_cursor < gnl_str->str_cursor + gnl_str->len)
	{
		if (*gnl_str->str_cursor == c)
			return (gnl_str->str_cursor);
		gnl_str->str_cursor++;
	}
	return (NULL);
}

char *parser(t_gnl_fd *fd_node, size_t len)
{
	char		*str = malloc(sizeof(char) * (len + 1));
	size_t		idx;
	t_gnl_str	*tmp;
	
	if (str == NULL || len == 0)
		return (NULL);
	idx = 0;
	while (fd_node->buffer != NULL)
	{
		while (fd_node->buffer->str_cursor_prev <= fd_node->buffer->str_cursor 
			&& fd_node->buffer->str_cursor < fd_node->buffer->str + fd_node->buffer->len)
			str[idx++] = *fd_node->buffer->str_cursor_prev++;
		fd_node->buffer->str_cursor = fd_node->buffer->str_cursor_prev;
		if (fd_node->buffer->str + fd_node->buffer->len > fd_node->buffer->str_cursor_prev)
			break ;
		fd_node->buffer->str_cursor = fd_node->buffer->str_cursor_prev;
		free(fd_node->buffer->str);
		tmp = fd_node->buffer;
		fd_node->buffer = fd_node->buffer->front;
		free(tmp);
	}
	if (fd_node->buffer == NULL)
		fd_node->buf_cursor = NULL;
	str[idx] = '\0';
	return (str);
}

char *read_until_endl(t_gnl_fd *fd_node)
{
	size_t total_length;
	char *str;

	total_length = 0;
	if (fd_node->buf_cursor != NULL && gnl_strnchr(fd_node->buf_cursor, '\n') != NULL)
		return (parser(fd_node, total_length + fd_node->buf_cursor->str_cursor - fd_node->buf_cursor->str_cursor_prev + 1));
	while (1)
	{
		append_gnl_str(fd_node);
		// fd_node->buf_cursor = fd_node->buf_cursor->front;
		fd_node->buf_cursor->len = read(fd_node->fd, fd_node->buf_cursor->str, BUFFER_SIZE);
		if (fd_node->buf_cursor->len == -1)
			return (NULL);
		total_length += fd_node->buf_cursor->str_cursor - fd_node->buf_cursor->str_cursor_prev + 1;
		if (gnl_strnchr(fd_node->buf_cursor, '\n') != NULL)
			return (parser(fd_node, total_length));
		if (fd_node->buf_cursor->len == 0)
		{
			str = parser(fd_node, total_length);
			return (str);
		}
	}
	return (NULL);
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

// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
// ! TESTER
#include <stdio.h>
#include <string.h>

void test_result(const char *prefix, int test_num, int failed_cnt)
{
	printf("[%s] OK: %d, KO: %d\n", prefix, test_num - 1 - failed_cnt, failed_cnt);
}

int test_numeric(const char *prefix, int test_num, long long result, long long expected)
{
	if (result != expected)
	{
		printf("[KO] %s <%d> result : %lld, expected: %lld\n", prefix, test_num, result, expected);
		return 1;
	}
	return 0;
}

int test_ptr(const char *prefix, int test_num, const void *result, const void *expected)
{
	if (result != expected)
	{
		printf("[KO] %s <%d> result : %p, expected: %p\n", prefix, test_num, result, expected);
		return 1;
	}
	return 0;
}

int test_str(const char *prefix, int test_num, const char *result, const char *expected)
{
	if (result != expected && (result == NULL || expected == NULL || strncmp(result, expected, strlen(expected)) != 0))
	{
		printf("[KO] %s <%d> result : %s, expected: %s\n", prefix, test_num, result, expected);
		return 1;
	}
	return 0;
}

int test_ptr_not(const char *prefix, int test_num, const void *result, const void *expected)
{
	if (result == expected)
	{
		printf("[KO] %s <%d>\n", prefix, test_num);
		return 1;
	}
	return 0;
}

void test_insert_gnl_fd()
{
	t_gnl_fd dummy = {-1, NULL, NULL, NULL, NULL};
	insert_gnl_fd(&dummy, 4);
	insert_gnl_fd(&dummy, 3);
	insert_gnl_fd(&dummy, 2);
	insert_gnl_fd(&dummy, 1);
	const char *const function_name = "test_insert_gnl_fd";
	int test_num = 1;
	int failed_cnt = 0;
	failed_cnt += test_numeric(function_name, test_num++,
							   dummy.fd, -1);
	failed_cnt += test_numeric(function_name, test_num++,
							   dummy.front->fd, 1);
	failed_cnt += test_numeric(function_name, test_num++,
							   dummy.front->front->fd, 2);
	failed_cnt += test_numeric(function_name, test_num++,
							   dummy.front->front->front->fd, 3);
	failed_cnt += test_numeric(function_name, test_num++,
							   dummy.front->front->front->front->fd, 4);
	test_result(function_name, test_num, failed_cnt);
	free_all_gnl_fd(dummy.front);
}

void test_find_fd()
{
	t_gnl_fd dummy = {-1, NULL, NULL, NULL, NULL};
	insert_gnl_fd(&dummy, 4);
	insert_gnl_fd(&dummy, 3);
	insert_gnl_fd(&dummy, 2);
	insert_gnl_fd(&dummy, 1);
	const char *const function_name = "test_find_fd";
	int test_num = 1;
	int failed_cnt = 0;
	t_gnl_fd *found;
	found = find_fd(&dummy, 1);
	failed_cnt += test_ptr(function_name, test_num++,
						   find_fd(&dummy, -1), &dummy);
	failed_cnt += test_ptr(function_name, test_num++,
						   find_fd(&dummy, 1), dummy.front);
	failed_cnt += test_ptr(function_name, test_num++,
						   find_fd(&dummy, 2), dummy.front->front);
	failed_cnt += test_ptr(function_name, test_num++,
						   find_fd(&dummy, 3), dummy.front->front->front);
	failed_cnt += test_ptr(function_name, test_num++,
						   find_fd(&dummy, 4), dummy.front->front->front->front);
	failed_cnt += test_ptr(function_name, test_num++,
						   find_fd(&dummy, 5), find_fd(&dummy, 5));
	test_result(function_name, test_num, failed_cnt);
	free_all_gnl_fd(dummy.front);
}

void test_append_gnl_str()
{
	t_gnl_fd dummy = {-1, NULL, NULL, NULL, NULL};
	find_fd(&dummy, 1);
	const int node_cnt = 4;
	t_gnl_str *arr[5] = { NULL, };
	for (int i = 0; i < node_cnt; i++)
	{
		arr[i] = append_gnl_str(dummy.front);
		// if (dummy.front->buf_cursor->front != NULL)
		// 	dummy.front->buf_cursor = dummy.front->buf_cursor->front;
	}
	const char *const function_name = "test_append_gnl_str";
	int test_num = 1;
	int failed_cnt = 0;
	const t_gnl_str *ptr = dummy.front->buffer;
	for(int i = 0; i < node_cnt; i++) {
		failed_cnt += test_ptr(function_name, test_num++,
								ptr, arr[i]);
		ptr = ptr->front;
	}
	failed_cnt += test_ptr(function_name, test_num++,
								ptr, arr[node_cnt]);
	test_result(function_name, test_num, failed_cnt);
	free_all_gnl_fd(dummy.front);
}

void test_ft_strnchr()
{
	t_gnl_str	gnl_str;
	gnl_str.len = 8;
	gnl_str.front = NULL;
	gnl_str.str = "abc\ndef";
	gnl_str.str_cursor = gnl_str.str;
	gnl_str.str_cursor_prev = gnl_str.str;
	const char *const function_name = "test_ft_strnchr";
	int test_num = 1;
	int failed_cnt = 0;
	for (int i = 0; i < gnl_str.len; i++)
	{
		gnl_strnchr(&gnl_str, gnl_str.str[i]);
		failed_cnt += test_ptr(function_name, test_num++,
								gnl_str.str_cursor, gnl_str.str + i);
		gnl_str.str_cursor++;
		gnl_str.str_cursor_prev = gnl_str.str_cursor;
	}
	for (int i = 0; i < gnl_str.len; i++)
	{
		gnl_strnchr(&gnl_str, gnl_str.str[i]);
		failed_cnt += test_ptr_not(function_name, test_num++,
								gnl_str.str_cursor, gnl_str.str + i);
	}
	test_result(function_name, test_num, failed_cnt);
}

void test_read_until_endl()
{
	t_gnl_fd dummy = {-1, NULL, NULL, NULL, NULL};
	int fd[] = {
		open("input1.txt", O_RDONLY),
		open("input2.txt", O_RDONLY),
		};
	const char * ans[] = {
		"S20****************E\n",
		"S20****************E\n",
		"S10******E\n",
		"S20****************E\n",
		"S20****************E",
		NULL,
	};
	const char *const function_name = "test_read_until_endl";
	int test_num = 1;
	int failed_cnt = 0;
	char * result;
	for (int i = 0; i < 6; i++)
	{
		result  = read_until_endl(find_fd(&dummy, fd[1]));
		visualize_gnl_str(find_fd(&dummy, fd[1])->buffer);
		failed_cnt += test_str(function_name, test_num++,
							result,
							ans[i]);
		free(result);
	}
	test_result(function_name, test_num, failed_cnt);
	close(fd[0]);
	close(fd[1]);
	free_all_gnl_fd(dummy.front);
}

void test_parser()
{
	t_gnl_fd dummy = {-1, NULL, NULL, NULL, NULL};
	find_fd(&dummy, 1);
	append_gnl_str(find_fd(&dummy, 1));
	char *str = "S20****************E\nS20****************E\nS10******E\nS20****************E\nS20****************E";
	const char * ans[] = {
		"S20****************E\n",
		"S20****************E\n",
		"S10******E\n",
		"S20****************E\n",
		"S20****************E",
		NULL,
	};
	char *s = find_fd(&dummy, 1)->buf_cursor->str;
	size_t idx = 0;
	while(str[idx])
	{
		s[idx] = str[idx];
		idx++;
	}
	find_fd(&dummy, 1)->buf_cursor->len = 94;
	const char *const function_name = "test_parser";
	int test_num = 1;
	int failed_cnt = 0;
	// printf("[DEBUG] %s\n", find_fd(&dummy, 1)->buf_cursor->str_cursor);
	find_fd(&dummy, 1)->buf_cursor->str_cursor += 20;
	char *result = parser(find_fd(&dummy, 1), 20);
	failed_cnt += test_str(function_name, test_num++,
						   result,
						   "S20****************E\n");
	free(result);
	find_fd(&dummy, 1)->buf_cursor->str_cursor += 20;
	result = parser(find_fd(&dummy, 1), 20);
	failed_cnt += test_str(function_name, test_num++,
						   result,
						   "S20****************E\n");
	free(result);
	find_fd(&dummy, 1)->buf_cursor->str_cursor += 10;
	result = parser(find_fd(&dummy, 1), 10);
	failed_cnt += test_str(function_name, test_num++,
						   result,
						   "S10******E\n");
	free(result);
	find_fd(&dummy, 1)->buf_cursor->str_cursor += 20;
	result = parser(find_fd(&dummy, 1), 20);
	failed_cnt += test_str(function_name, test_num++,
						   result,
						   "S20****************E\n");
	free(result);
	find_fd(&dummy, 1)->buf_cursor->str_cursor += 20;
	result = parser(find_fd(&dummy, 1), 20);
	failed_cnt += test_str(function_name, test_num++,
						   result,
						   "S20****************E");
	free(result);
	find_fd(&dummy, 1)->buf_cursor->str_cursor += 0;
	result = parser(find_fd(&dummy, 1), 0);
	printf("[DEBUG] [%s]\n", result);
	failed_cnt += test_ptr(function_name, test_num++,
						   result,
						   NULL);
	free(result);
	test_result(function_name, test_num, failed_cnt);
	free_all_gnl_fd(dummy.front);
}

/*
_____
| \n|
_____
*/
#include <stdio.h>
void visualize_gnl_str(t_gnl_str *gnl_str)
{
	// pointer(prev)
	for(int i = 0; i < gnl_str->len; i++) {
		if (gnl_str->str_cursor_prev == gnl_str->str + i)
			printf("  V  ");
		else
			printf("     ");
	}
	printf("\n");
	// top
	for(int i = 0; i < gnl_str->len; i++)
		printf("_____");
	printf("\n");
	// mid(content)
	for(int i = 0; i < gnl_str->len; i++)
		printf("| %c%c ", 
			(gnl_str->str[i] == '\n' || gnl_str->str[i] == '\0' ? '\\' : gnl_str->str[i]),
			(gnl_str->str[i] == '\n' ? 'n' : gnl_str->str[i] =='\0' ? '0' : ' ' )
			);
	printf("\n");
	// bottom
	for(int i = 0; i < gnl_str->len; i++)
		printf("_____");
	printf("\n");
	// pointer(cur)
	for(int i = 0; i < gnl_str->len; i++) {
		if (gnl_str->str_cursor == gnl_str->str + i)
			printf("  ^  ");
		else
			printf("     ");
	}
	printf("\n");
}

int main()
{
	test_insert_gnl_fd();
	test_find_fd();
	test_append_gnl_str();
	test_ft_strnchr();
	test_read_until_endl();
	// test_parser();
	return 0;
}