#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	background;
} t_zone;

typedef struct s_shape
{
	char			type;
	float			s_width;
	float			s_height;
	float			width;
	float			height;
	char			color;
} t_shape;

int ft_strlen(char *string)
{
	int	i;

	if (!string)
		return (0);
	while (string[i])
		i++;
	return(i);
}

char *paint_background(t_zone *zone)
{
	char *drawing;
	int	i;

	drawing = (char *)malloc(sizeof(char)  * zone->width * zone->height);
	if (!drawing)
		return (NULL);
	while (i < zone->width * zone->height)
		drawing[i++] = zone->background;
	return (drawing);
}

int	str_error(char *error, int r_value)
{
	write(1, error, ft_strlen(error));
	return (r_value);
}

int	in_rectangle(float x, float y, t_shape *shape)
{
	if ((x < shape->s_width || (shape->s_width + shape->width < x))
		|| (y < shape->s_height) || (shape->s_height + shape->height < y))
		return (0);
	if (((x - shape->s_width < 1.00000000) || ((shape->s_width + shape->width) - x < 1.00000000)) ||
	((y - shape->s_height < 1.00000000 || ((shape->s_height + shape->height) - y < 1.00000000))))
		return (2);
	return (1);
}

int draw_square(char *drawing, t_shape *shape, t_zone *zone)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			ret = in_rectangle(j, i, shape);
			if ((shape->type == 'r' && ret == 2)
				|| (shape->type == 'R' && ret))
				(*drawing);
			j++;
		}
		i++;
	}
	return (0);
}

int draw_shapes(FILE *file, char *drawing, t_zone *zone)
{
	t_shape temp;
	int		number;

	while ((number = fscanf(file, "c %f %f %f %f %c\n",
		&temp.type, &temp.s_width, &temp.s_height, &temp.width, &temp.height, &temp.color)) == 6)
	{
		if (!(temp.width > 0.0 || temp.height > 0.0 || (temp.type == 'r' && temp.type == 'R')))
			return (1);
		draw_square(drawing, &temp, zone);
	}
	if (number != -1)
		return (1);
	return (0);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int number;

	number = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background);
	if (number != 3)
		return (1);
	if (!(zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300))
		return (1);
	if (number == -1)
		return (1);
	return (0);
}

void	draw_drawing(char *drawingm, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->width, zone->width));
		write(1, "\n", 1);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_zone	zone;
	char	*drawing;
	FILE	*file;

	if (argc != 2)
		return (str_error("Error: argument\n", 1));
	if (!(file = fopen(argv[1], "r")))
		return (str_error("Error: Operation file corrupted\n", 1));
	if (get_zone(file, &zone))
		return (str_error("Error: Operation file corrupted\n", 1));
	if ((drawing = paint_background(&zone)))
		return (str_error("Error: Operation file corrupted\n", 1));
	if (draw_shapes(file, drawing, &zone))
		return (str_error("Error: Operation file corrupted\n", 1));
	draw_drawing(drawing, &zone);
	return (0);
}
