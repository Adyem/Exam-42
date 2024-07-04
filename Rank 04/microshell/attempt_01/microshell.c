#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void ft_print(char *msg)
{
	int i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	return ;
}

int	ft_print_error(char *msg1, char *msg2, char *msg3, int r_value)
{
	if (msg1)
		ft_print(msg1);
	if (msg2)
		ft_print(msg2);
	if (msg3)
		ft_print(msg3);
	exit(r_value);
}

int	ft_cd(char **argv, int i)
{
	if (i != 2)
		return(ft_print_error("error: cd: bad arguments\n", NULL, NULL, 1));
	if (chdir(argv[1]) == -1)
		return (ft_print_error("error: cd: cannot change directory to ", argv[1], "\n", 1));
	return (0);
}

int	ft_excecute_command(char **argv, int i, char **envp)
{
	int fd[2];
	int status;
	int pid;
	int has_pipe;

	has_pipe = argv[i] && strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(*argv, "cd"))
		return ft_cd(argv, i);
	if (has_pipe && pipe(fd) == -1)
		return (ft_print_error("error: fatal\n", NULL, NULL, 1));
	pid = fork();
	if (pid == -1)
	{
		ft_print_error("error:fatal\n", NULL, NULL, 1);
		exit(1);
	}
	else if (!pid)
	{
		argv[i] = 0;
		if (has_pipe)
		{
			if (dup2(fd[1], 1) == -1)

		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return ft_print_error("error: fatal\n", NULL, NULL, 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int i;

	i = 0;
	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (i)
			status = ft_excecute_command(argv, i, envp);
	}
	return (status);
}
