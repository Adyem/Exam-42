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
	return (1);
}

int	ft_cd(char **argv, int i)
{
	if (i != 2 || !argv[1])
		return (ft_putstr_fd2("error: cd: bad arguments", NULL));
	if (chdir(argv[1]) == -1)
		return (ft_putstr_fd2("error: cd: cannot change directory to", argv[1]));
	return (0);
}

int main(int argc, char **argv, char **env)
{
	int	i;
	int	fd[2];
	int	tmp_fd;
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
	}
	close(tmp_fd);
	return (0);
}
