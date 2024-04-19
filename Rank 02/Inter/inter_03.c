#include <unistd.h>

int	check(char *string1, char *string2, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (string1[index] == string1[i])
			return (0);
		i++;
	}
	i = 0;
	while (string2[i])
	{
		if (string2[i] == string1[index])
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *string1, char *string2)
{
	int	i;

	i = 0;
	while (string1[i])
	{
		if (check(string1, string2, i) == 1)
			write (1, &string1[i], 1);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	char	c;

	c = '\n';
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, &c, 1);
	return (0);
}
