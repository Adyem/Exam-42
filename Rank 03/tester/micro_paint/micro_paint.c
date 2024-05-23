#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define TOLERANCE 0.000001

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
	while (i < (int)height)
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
	//printf("the height of the canves is %f\n", height);
	//printf("the width of the canves is %f\n", width);
	return (canves);
}

int is_in_rectangle(float x, float y, float rect_x, float rect_y, float rect_width, float rect_height)
{
    if (x < rect_x || x > rect_x + rect_width
			|| y < rect_y || y > rect_y + rect_height)
        return 0; // Outside
    if ((x - rect_x < 1.0) || (rect_x + rect_width - x < 1.0) || 
        (y - rect_y < 1.0) || (rect_y + rect_height - y < 1.0))
        return 2; // Border
    return 1; // Inside
}

int	ft_draw_square(char **canvas, FILE *file)
{
	char	filled;
	char	symbol;
	float	s_width;
	float	s_height;
	float	width;
	float	height;
	int		number;
	int		i;
	int		j;
	int		pos;

	number = fscanf(file, "%c %f %f %f %f %c\n", &filled, &s_width, &s_height, &width, &height, &symbol);
	while (number == 6)
	{
		//printf("%c %i %i %f %f %f %f %c %i\n", filled, i, j, s_width, s_height, width, height, symbol, number);
		if (height <= 0.0 || width <= 0.0 || (filled != 'r' && filled != 'R'))
			return 1;
		i = 0;
		while (canvas[i])
		{
			j = 0;
			while (canvas[i][j])
			{
				float i_float = (float)i;
				float j_float = (float)j;
				pos = is_in_rectangle(j_float, i_float, s_width, s_height, width, height);

				if ((pos == 1 || pos == 2) && filled == 'R')
					canvas[i][j] = symbol;
				else if (pos == 2 && filled == 'r')
					canvas[i][j] = symbol;
				j++;
			}
			i++;
		}

		number = fscanf(file, "%c %f %f %f %f %c\n", &filled, &s_width, &s_height, &width, &height, &symbol);
	}

	if (number != -1 && number != 6)
		return 1;

	return 0;
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
		return (ft_error("Error: Operation file corrupted\n"));
	number = fscanf(file, "%f %f %c\n", &width, &height, &symbol);
	//printf("amount of symbols = %i\n", number);
	if (number != 3)
		return (ft_error("Error: Operation file corrupted\n"));
	canves = ft_draw_canvis(symbol, width, height);
	if (!canves)
		return (ft_error("Error: Operation file corrupted\n"));
	error = 0;
	if (ft_draw_square(canves, file))
		error = ft_error("Error: Operation file corrupted\n");
	if (!error)
		ft_print_canves(canves);
	fclose(file);
	ft_free_canves(canves);
	return (error);
}
