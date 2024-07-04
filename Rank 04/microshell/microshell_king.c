#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int printerror(char	*str1, char *str2)
{
	int i;

	if (!str1)
		return (1);
	i = 0;
	while (str1[i])
	{
		write(2, &str1[i], 1);
		i++;
	}
	i = 0;
	if (str2)
	{
		while (str2[i])
		{
			write(2, &str2[i], 1);
			i++;
		}
	}
	write(2, "\n", 1);
	return (1);
}

void ft_execute(char **arg, int i, int tmp_fd, char **env)
{
	arg[i] = NULL;
	dup2(tmp_fd, 0);
	close(tmp_fd);
	execve(arg[0], arg, env);
	printerror("error: cannot execute ", arg[0]);
	exit(1);
}


int	main(int argc, char **argv, char **env)
{
	int		i;
	int		pip[2];
	int		tmp_fd;
	int		pid;
	char	**arg;

	(void)argc;
	tmp_fd = dup(0);
	if (!tmp_fd)
		return (printerror("error: fatal", NULL));
	i = 0;
	arg = argv;
	while (arg[i] && arg[i + 1])
	{
		arg = &arg[i + 1];
		i = 0;
		while (arg[i] && strcmp(arg[i], ";") && strcmp(arg[i], "|"))
			i++;
		if (!strcmp(arg[0], "cd"))
		{
			if (i != 2)
				printerror("error: cd: bad arguments", NULL);
			else if (chdir(arg[1]) != 0)
				printerror("error: cd: cannot change directory to ", arg[1]);
		}
		else if (i != 0 && (!arg[i] || !strcmp(arg[i], ";")))
		{
			pid = fork();
			if (pid == 0)
				ft_execute(arg, i, tmp_fd, env);
			else if (pid < 0)
				printerror("error: fatal", NULL);
			else
			{
				close(tmp_fd);
				waitpid(pid, NULL, 0);
				tmp_fd = dup(0);
			}
		}
		else if(i != 0 && !strcmp(arg[i], "|"))
		{
			pipe(pip);
			pid = fork();
			if (pid == 0)
			{
				dup2(pip[1], 1);
				close(pip[0]);
				close(pip[1]);
				ft_execute(arg, i, tmp_fd, env);
			}
			else if (pid < 0)
				printerror("error: fatal", NULL);
			else
			{
				close(pip[1]);
				close(tmp_fd);
				tmp_fd = pip[0];
				waitpid(pid, NULL, 0);
			}
		}
	}
	close(tmp_fd);
	return (0);
}
