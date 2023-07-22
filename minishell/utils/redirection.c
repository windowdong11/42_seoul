#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef enum e_pipe_fd
{
	pipe_fd_read = 0,
	pipe_fd_write = 1,
}	t_pipe_fd;

int main(int argc, char *argv[])
{
	char *arg[] = {"cat", NULL};
	// int infile = open("in_file", O_RDONLY);
	// int outfile = open("out_file", O_WRONLY);

	int pipe_fd[1000];

	// printf("%d\n", infile);
	// printf("%d\n", outfile);
	pipe(pipe_fd);
	pipe(pipe_fd + 2);
	if (fork() == 0)
	{
		// change stdin
		// dup2(infile, STDIN_FILENO);
		// change stdout
		close(pipe_fd[2 * 0 + pipe_fd_read]);
		dup2(pipe_fd[2 * 0 + pipe_fd_write], STDOUT_FILENO);
		execvp("cat", arg);
	}
	else if (fork() == 0)
	{
		// change stdin
		close(pipe_fd[2 * 0 + pipe_fd_write]);
		dup2(pipe_fd[2 * 0 + pipe_fd_read], STDIN_FILENO);
		// change stdout
		close(pipe_fd[2 * 1 + pipe_fd_read]);
		dup2(pipe_fd[2 * 1 + pipe_fd_write], STDOUT_FILENO);
		execvp("cat", arg);
	}
	else if (fork() == 0)
	{
		// change stdin
		close(pipe_fd[2 * 1 + pipe_fd_write]);
		dup2(pipe_fd[2 * 1 + pipe_fd_read], STDIN_FILENO);
		// change stdout
		// dup2(outfile, STDOUT_FILENO);
		execvp("cat", arg);
	}
	int stat;
	wait(&stat);
	return 0;
}