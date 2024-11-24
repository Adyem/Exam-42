#include <unistd.h>

void	ft_union(char *string1, char *string2)
{
	int	seen[256] = {0};
	int	i;

	i = 0;
	while (string1[i])
	{
		if (!seen[(int)string1[i]])
		{
			write(1, &string1[i], 1);
			seen[(int)string1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (string2[i])
	{
		if (!seen[(int)string2[i]])
		{
			write(1, &string2[i], 1);
			seen[(int)string2[i]] = 1;
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write (1, "\n", 1);
	return (0);
}
