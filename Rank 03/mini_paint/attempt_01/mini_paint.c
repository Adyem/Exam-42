#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int ft_strlen(char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

int ft_error(char *msg, int rvalue)
{
	write(1, msg, ft_strlen(msg));
	return (rvalue);
}

char	**ft_make_canves(FILE *file)
{
	float	hight;
	float	width;
	char	symbol;
	int		number;
	int		i;
	int		j;
	char	**canves;

	number = fscanf(file, "%f %f %c\n", &width, &hight, &symbol);
	if (number != 3)
		return (NULL);
	if (width <= 0 || hight <= 0 || width > 300 || hight > 300)
		return (NULL);
	canves = (char **)malloc((hight + 1) * sizeof(char *));
	if (!canves)
		return (NULL);
	i = 0;
	while (i < hight)
	{
		j = 0;
		canves[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!canves[i])
			return (NULL);
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

int	ft_check_pos(float floati, float floatj, float s_width, float s_hight, float radius)
{
	float	distance;

	distance = sqrtf(powf(floati - s_hight, 2.) + powf(floatj - s_width, 2.));
	if (distance <= radius)
	{
		printf("checking\n");
		if (radius - distance < 1.0)
			return (2);
		return (1);
	}
	return (0);
}

int	ft_draw_circle(FILE *file, char **canves)
{
	float	radius;
	float	s_hight;
	float	s_width;
	char	symbol;
	char	filled;
	int		number;
	int		i;
	int		j;
	float	floati;
	float	floatj;
	int		pos;

	while ((number = fscanf(file, "%c %f %f %f %c\n", &filled, &s_width, &s_hight, &radius, &symbol)) == 5)
	{
		if (radius < 0.0 || (filled != 'c' && filled != 'C'))
			return (1);
		i = 0;
		printf("test\n");
		while (canves[i])
		{
			j = 0;
			while (canves[i][j])
			{
				floati = (float)i;
				floatj = (float)j;
				pos = ft_check_pos(floati, floatj, s_width, s_hight, radius);
				if ((pos == 1 || pos == 2) && filled == 'C')
					canves[i][j] = symbol;
				else if (pos == 2 && filled == 'c')
					canves[i][j] = symbol;
				j++;
			}
			i++;
		}
	}
	printf("number = %i", number);
	if (number != -1 && number != 5)
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

int main(int argc, char **argv)
{
	FILE	*file;
	char	**canves;

	if (argc != 2)
		return (ft_error("Error: Argument\n", 1));
	file = fopen(argv[1], "r");
	if (!file)
		return (ft_error("Error: Operation file corrupted\n", 1));
	canves = ft_make_canves(file);
	if (!canves)
		return (ft_error("Error: Operation file corrupted\n", 1));
	ft_print_canves(canves);
	return (0);
}
