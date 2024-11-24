#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_error(char *msg, char *msg2, int error)
{
	int i;

	i = 0;
	if (msg)
	{
		while (msg[i])
		{
			write(2, &msg[i], 1);
			i++;
		}
	}
	i = 0;
	if (msg2)
	{
		while (msg2[i])
		{
			write(2, &msg2[i], 1);
			i++;
		}
	}
	write (2, "\n", 1);
	if (error)
		exit(1);
	return ;
}

void	ft_excecute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	dup2(tmp_fd, 0);
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_error("error: cannot excecute", NULL, 1);
}

int main(int argc, char **argv, char **env)
{
	int i;
	int tmp_fd;
	int status;
	int pipe_fd[2];
	pid_t pid;

	(void)argc;
	i = 0;
	tmp_fd = dup(0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_error("error: cd: bad arguments", NULL, 1);
			if (chdir(argv[1]) == -1)
				ft_error("error: cd: cannot change directory to ", argv[1], 0);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if (pid == -1)
				ft_error("error: fatal", NULL, 1);
			else if (pid == 0)
				ft_excecute(argv, i, tmp_fd, env);
			else
			{
				close(tmp_fd);
				waitpid(1, &status, 0);
				tmp_fd = dup(0);
				continue ;
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			if (pipe(pipe_fd))
				ft_error("error: fatal", NULL, 1);
			pid = fork();
			if (pid == -1)
				ft_error("error: fatal", NULL, 1);
			else if (pid == 0)
			{
				dup2(pipe_fd[1], 1);
				close(pipe_fd[1]);
				close(pipe_fd[0]);
				ft_excecute(argv, i, tmp_fd, env);
			}
			else
			{
				close(pipe_fd[1]);
				close(tmp_fd);
				waitpid(1, &status, 0);
				tmp_fd = pipe_fd[0];
				continue ;
			}
		}
	}
	close(tmp_fd);
	return (0);
}
