#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *string)
{
	int i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	ft_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

char	**ft_free_canves(char **canves)
{
	int	i;

	i = 0;
	while (canves[i])
	{
		free(canves[i]);
		i++;
	}
	free(canves);
	return (NULL);
}

char	**ft_draw_canvis(char symbol, float width, float height)
{
	char	**canves;
	int		i;
	int		j;

	if (width > 300 || height > 300 || width < 1 || height < 1)
		return (NULL);
	canves = (char **)malloc((sizeof(char *) * ((int)height + 1)));
	if (!canves)
		return (NULL);
	i = 0;
	while (i < height)
	{
		canves[i] = (char *)malloc(sizeof(char) * ((int)width + 1));
		if (!canves[i])
			return (ft_free_canves(canves));
		j = 0;
		while (j < (int)width)
		{
			canves[i][j] = symbol;
			j++;
		}
		canves[i][j] = '\0';
		i++;
	}
	canves[i] = NULL;
	printf("the height of the canves is %f\n", height);
	printf("the width of the canves is %f\n", width);
	return (canves);
}

int	ft_draw_square(char **canves, FILE *file)
{
	char	filled;
	char	symbol;
	float	s_width;
	float	s_height;
	float	width;
	float	height;
	float	t_width;
	float	t_height;
	int		number;
	int		i;
	int		j;

	while ((number = fscanf(file, "%s %f %f %f %f %s", &filled, &s_width, &s_height, &width, &height, &symbol)) == 6)
	{
		printf("amount of symbols = %i\n", number);
		t_width = width + s_width;
		t_height = height + s_height;
		i = 0;
		j = 0;
		printf("%c %f %f %f %f %c\n", filled, s_width, s_height, t_width, t_height, symbol);
		while (canves[i])
		{
			j = 0;
			while (canves[i][j])
			{
				if ((i > (int)s_height) && (i <= (int)t_height)
						&& (j > (int)s_width) && (j <= (int)t_width)) 
				{
					if (filled == 'R')
						canves[i][j] = symbol;
					else if (filled == 'r')
					{
						if ((i == (int)s_height + 1) || (i == (int)t_height)
								|| (j == (int)s_width + 1) || (j == (int)t_width))
							canves[i][j] = symbol;
					}
				}
				j++;
			}
			i++;
		}
	}
	printf("amount of symbols = %i\n", number);
	if (number != -1)
		return (1);
	return (0);
}

void	ft_print_canves(char **canves)
{
	int	i;
	int	j;

	i = 0;
	while (canves[i])
	{
		j = 0;
		while (canves[i][j])
		{
			write(1, &canves[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*file;
	float	width;
	float	height;
	char	symbol;
	int		number;
	char	**canves;
	int		error;

	if (argc != 2)
		return (ft_error("Error: Argument\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (ft_error("1-Error: Operation file corrupted\n"));
	number = fscanf(file, "%f %f %c", &width, &height, &symbol);
	printf("amount of symbols = %i\n", number);
	if (number != 3)
		return (ft_error("Error: Operation file corrupted\n"));
	canves = ft_draw_canvis(symbol, width, height);
	if (!canves)
		return (ft_error("2-Error: Operation file is corrupted\n"));
	error = 0;
	if (ft_draw_square(canves, file))
		error = ft_error("3-Error: Operation file is corrupted\n");
	if (!error)
		ft_print_canves(canves);
	fclose(file);
	ft_free_canves(canves);
	return (error);
}
