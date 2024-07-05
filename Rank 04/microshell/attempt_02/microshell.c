#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int	ft_putstr_fd2(char *str, char *arg)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	i = 0;
	if (arg)
	{
		while (arg[i])
		{
			write(2, &arg[i], 1);
			i++;
		}
	}
	write(2, "\n", 1);
	exit (1);
}

int	ft_cd(char **argv, int i)
{
	if (i != 2 || !argv[1])
		return (ft_putstr_fd2("error: cd: bad arguments", NULL));
	if (chdir(argv[1]) == -1)
		return (ft_putstr_fd2("error: cd: cannot change directory to", argv[1]));
	return (0);
}

void	ft_excecute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_putstr_fd2("error: cannot excecute ", argv[0]);
	exit(1);
}

int main(int argc, char **argv, char **env)
{
	int	i;
	int	fd[2];
	int	tmp_fd;
	int status;
	(void)argc;

	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			ft_cd(argv, i);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
				ft_excecute(argv, i, tmp_fd, env);
			else
			{
				close(tmp_fd);
				waitpid(-1, &status, 0);
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				ft_excecute(argv, i, tmp_fd, env);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				waitpid(-1, &status, 0);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}
