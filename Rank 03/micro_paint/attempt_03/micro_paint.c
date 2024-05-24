#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *string)
{
	int i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

int ft_error(char *msg, int error)
{
	write(1, msg, ft_strlen(msg));
	return (error);
}

char **ft_make_canves(FILE *file)
{
	float	width;
	float	hight;
	char	symbol;
	int		number;
	int		i;
	int		j;
	char	**canves;

	number = fscanf(file, "%f %f %c\n", &width, &hight, &symbol);
	if (number != 3)
		return (NULL);
	if (width > 300 || hight > 300 || width <= 0 || hight <= 0)
		return (NULL);
	canves = (char **)malloc((hight + 1) * sizeof(char *));
	if (!canves)
		return (NULL);
	i = 0;
	while (i < hight)
	{
		canves[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!canves[i])
			return (NULL);
		j = 0;
		while (j < width)
		{
			canves[i][j] = symbol;
			j++;
		}
		canves[i][j] = '\0';
		i++;
	}
	canves[i] = NULL;
	return (canves);
}

int	ft_check(float float_i, float float_j, float s_width, float s_hight, float width, float hight)
{
	if (float_i < s_hight || float_j < s_width || float_i > s_hight + hight || float_j > s_width + width)
		return (0);
	if ((float_i - s_hight < 1.0) || (s_hight + hight - float_i < 1.0)
			|| float_j - s_width < 1.0 || (s_width + width - float_j < 1.0))
			return (2);
	return (1);
}

int	ft_draw_sqaure(FILE *file, char **canves)
{
	float	width;
	float	hight;
	float	s_width;
	float	s_hight;
	float	float_i;
	float	float_j;
	int		i;
	int		j;
	char	filled;
	char	symbol;
	int		number;
	int		check;

	while ((number = fscanf(file, "%c %f %f %f %f %c\n", &filled, &s_width, &s_hight, &width, &hight, &symbol)) == 6)
	{
		if (width <= 0.0 || hight <= 0.0 || (filled != 'r' && filled != 'R'))
			return (1);
		i = 0;
		while (canves[i])
		{
			j = 0;
			while (canves[i][j])
			{
				float_i = (float)i;
				float_j = (float)j;
				check = ft_check(float_i, float_j, s_width, s_hight, width, hight);
				if ((check == 1 || check == 2) && filled == 'R')
					canves[i][j] = symbol;
				else if (check == 2 && filled == 'r')
					canves[i][j] = symbol;
				j++;
			}
			i++;
		}
	}
	if (number != -1 && number != 6)
		return (1);
	return (0);
}

void	ft_draw_canves(char **canves)
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

int main(int argc, char **argv)
{
	FILE	*file;
	char	**canves;

	if (argc != 2)
		return (ft_error("Error: argument\n", 1));
	file = fopen(argv[1], "r");
	if (!file)
		return (ft_error("Error: Operation file corrupted\n", 1));
	canves = ft_make_canves(file);
	if (!canves)
		return (ft_error("Error: Operation file corrupted\n", 1));
	if (ft_draw_sqaure(file, canves))
		return (ft_error("Error: Operation file corrupted\n", 1));
	ft_draw_canves(canves);
	return (0);
}
