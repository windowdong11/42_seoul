#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>

typedef enum e_pipe_fd
{
	pipe_fd_read = 0,
	pipe_fd_write = 1,
}	t_pipe_fd;

void	builtins_echo(char **args, int out_fd)
{
	size_t		idx;
	const int	n_flag = args[1] != NULL && ft_strncmp(args[1], "-n", 2) == 0;

	idx = 1 + n_flag;
	while (args[idx] != NULL)
	{
		write(out_fd, args[idx], ft_strlen(args[idx]));
		if (args[idx + 1] != NULL)
			write(out_fd, " ", 1);
		++idx;
	}
	if (n_flag == 0)
		write(out_fd, "\n", 1);
}

void	free_split(char**const splitted)
{
	size_t	idx;

	if (splitted == NULL)
		return;
	idx = 0;
	while (splitted[idx] != NULL)
	{
		free(splitted[idx]);
		++idx;
	}
	free(splitted);
}

/*
1. 파이프 열기
2. 커맨드 실행
	1. 빌트인 확인 & 실행
	2. execvp 실행
3. 마지막 프로세스 종료까지 기다림
 in | a   b   c   d | out
  i > 0 > 1 > 2 > 3 > o
  r:0   2   4   6   x
  w:x   3   5   7   9
  i:0   1   2   3   4
 cr:c   o   o   o   x
 cw:x   o   o   o   c
  (r, w)
  (0, 1)
  (2, 3)
  (4, 5)
  (6, 7)
*/
void	execute_pipe(char **commands, size_t n, int in, int out)
{
	char		**args;
	int*const	pipe_fd = malloc(sizeof(int) * (n * 2 + 2));
	size_t		idx;
	pid_t		fork_pid;

	printf("in : %d out : %d\n", in, out);
	pipe_fd[pipe_fd_read] = in;
	pipe_fd[pipe_fd_write] = -1;
	pipe_fd[2 * n + pipe_fd_read] = -1;
	pipe_fd[2 * n + pipe_fd_write] = out;
	// TODO : open 에러 처리
	idx = 1;
	while (idx < n)
	{
		pipe(pipe_fd + (2 * idx));
		++idx;
	}
	idx = 0;
	while (idx < n)
	{
		fork_pid = fork();
		if (fork_pid == 0)
		{
			printf("forked : %zu : %d\n", idx, getpid());
			if (idx != 0)
				close(pipe_fd[2 * idx + pipe_fd_write]);
			if (pipe_fd[2 * idx + pipe_fd_read] != STDIN_FILENO)
			{
				dup2(pipe_fd[2 * idx + pipe_fd_read], STDIN_FILENO);
				close(pipe_fd[2 * idx + pipe_fd_read]);
			}
			if (idx != n - 1)
				close(pipe_fd[2 * (idx + 1) + pipe_fd_read]);
			if (pipe_fd[2 * (idx + 1) + pipe_fd_write] != STDOUT_FILENO)
			{
				dup2(pipe_fd[2 * (idx + 1) + pipe_fd_write], STDOUT_FILENO);
				close(pipe_fd[2 * (idx + 1) + pipe_fd_write]);
			}
			args = ft_split(commands[idx], ' ');
			execvp(args[0], args);
			// TODO : execvp 에러 처리
			free_split(args);
			perror("Execvp failed.\n");
		}
		if (idx != 0)
			close(pipe_fd[2 * idx + pipe_fd_write]);
		if (pipe_fd[2 * idx + pipe_fd_read] != STDIN_FILENO)
			close(pipe_fd[2 * idx + pipe_fd_read]);
		++idx;
	}
	int stat_loc;
	idx = 0;
	while (idx < n) {
		// TODO : 프로세스 에러 처리
		printf("finish : %d\n", wait(&stat_loc));
		++idx;
	}
	free(pipe_fd);
}

void ft_leaks()
{
	const char *pid_str = ft_itoa(getpid());
	const size_t size = 6 + ft_strlen(pid_str) + 1;
	char *const command = malloc(sizeof(char) * size);
	
	command[0] = '\0';
	ft_strlcat(command, "leaks ", size);
	ft_strlcat(command, pid_str, size);
	system(command);
	free(command);
}

int open_redirection_stdin(const char *filename)
{
	int fd;

	if (filename == NULL)
		return STDIN_FILENO;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		// TODO : open 에러 처리
		perror("[Error] : open_redirection_stdin open");
		exit(1);
	}
	return fd;
}

int open_redirection_stdout(const char *stdout, int is_append_mode)
{
	int fd;

	if (stdout == NULL)
		return STDOUT_FILENO;
	if (is_append_mode)
		fd = open(stdout, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(stdout, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		// TODO : open 에러 처리
		perror("[Error] : open_redirection_stdout open");
		exit(1);
	}
	return fd;
}


int main(int argc, char **argv)
{
	atexit(ft_leaks);
	char**const	arr = malloc(sizeof(char *) * (argc - 1));
	arr[0] = ft_strdup("cat");
	arr[1] = ft_strdup("cat");
	char *in = NULL; // NULL or filename
	char *out = NULL; // NULL or filename
	int in_fd;
	int out_fd;
	in_fd = open_redirection_stdin(in);
	out_fd = open_redirection_stdout(out, 0);
	execute_pipe(arr, 2, in_fd, out_fd);
	free(arr[1]);
	free(arr[0]);
	free(arr);
	return 0;
}