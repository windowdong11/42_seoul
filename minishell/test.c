/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:29:35 by dowon             #+#    #+#             */
/*   Updated: 2023/07/11 22:39:58 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft/libft.h"

typedef struct s_pipe
{
	char	**infiles;
	char	**outfiles;
}	t_pipe;

typedef enum e_pipe_fd
{
	pipe_fd_read = 0,
	pipe_fd_write = 1,
}	t_pipe_fd;


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
1. open infiles, outfiles
2. exec commands
3. get exec result
 in | a   b   c   d | out
  i > 0 > 1 > 2 > 3 > o
  r:0   2   4   6   8(x)
  w:1   3   5   7   9
  (r, w)
  (0, 1)
  (2, 3)
  (4, 5)
  (6, 7)
in | a   b | out
  i > 0 > 1 > o
  r:3   5
  w:    6   4
    0x  2   4x
	1x  3   5x
*/
void execute_pipe(char **commands, size_t n)
{
	char***const	args = malloc(sizeof(char**) * n);
	int*const		pipe_fd = malloc(sizeof(int) * (n * 2 + 2));
	size_t			idx;
	pid_t			fork_pid;

	pipe_fd[2 * 0 + pipe_fd_read] = open("note.md", O_RDONLY);
	pipe_fd[2 * 0 + pipe_fd_write] = -1;
	pipe_fd[2 * n + pipe_fd_read] = -1;
	pipe_fd[2 * n + pipe_fd_write] = open("test.md", O_WRONLY);
	printf("%d %d\n", pipe_fd[0], pipe_fd[2 * n + 1]);
	idx = 1;
	while (idx < n)
		pipe(pipe_fd + 2 * idx++);
	idx = 0;
	while (idx < n)
	{
		fork_pid = fork();
		if (fork_pid == 0)
		{
			pid_t cur_pid = getpid();
			printf("child %d : read %d write %d\n",
				getpid(),
				pipe_fd[2 * idx + pipe_fd_read],
				pipe_fd[2 * idx + pipe_fd_write]);
			if (idx != 0)
				close(pipe_fd[2 * idx + pipe_fd_write]);
			dup2(pipe_fd[2 * idx + pipe_fd_read], STDIN_FILENO);
			if (idx != n - 1)
				close(pipe_fd[2 * (idx + 1) + pipe_fd_read]);
			dup2(pipe_fd[2 * (idx + 1) + pipe_fd_write], STDOUT_FILENO);
			args[idx] = ft_split(commands[idx], ' ');
			execvp(args[idx][0], args[idx]);
		}
		++idx;
	}
	int stat_loc;
	wait(&stat_loc);
	printf("%d\n", stat_loc);
	wait(&stat_loc);
	printf("%d\n", stat_loc);
	wait(&stat_loc);
	printf("%d\n", stat_loc);
	// free_split(args[idx]);
	// args[idx] = NULL;
}

int main()
{
	char **arr = malloc(sizeof(char *) * 2);
	arr[0] = ft_strdup("cat");
	arr[1] = ft_strdup("cat");
	execute_pipe(arr, 2);
	free(arr[1]);
	free(arr[0]);
	free(arr);
	return 0;
}