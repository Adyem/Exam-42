#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 300
#define MAX_HEIGHT 300

typedef struct {
    int width, height;
    char background_char;
    char canvas[MAX_HEIGHT][MAX_WIDTH];
} Drawing;

void initialize_drawing(Drawing *drawing, int width, int height, char bg_char) {
    drawing->width = width;
    drawing->height = height;
    drawing->background_char = bg_char;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            drawing->canvas[i][j] = bg_char;
}

void print_drawing(const Drawing *drawing) {
    for (int i = 0; i < drawing->height; i++) {
        for (int j = 0; j < drawing->width; j++)
            putchar(drawing->canvas[i][j]);
        putchar('\n');
    }
}

void draw_rectangle(Drawing *drawing, char type, float x, float y, float width, float height, char ch)
{
    int max_x = (int)(x + width);
    int max_y = (int)(y + height);
	int i;

	i = 0;
    while (i < drawing->height) {
        for (int j = 0; j < drawing->width; j++) {
            if (type == 'R') {
                if (j >= x && j < max_x && i >= y && i < max_y)
                    drawing->canvas[i][j] = ch;
            } else if (type == 'r') {
                if ((j == (int)x || j == max_x - 1) && i >= y && i < max_y)
                    drawing->canvas[i][j] = ch;
                if ((i == (int)y || i == max_y - 1) && j >= x && j < max_x)
                    drawing->canvas[i][j] = ch;
            }
        }
        i++;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: argument\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Operation file corrupted\n");
        return 1;
    }

    Drawing drawing;
    int width, height;
    char bg_char;
    if (fscanf(file, "%d %d %c\n", &width, &height, &bg_char) != 3 || width <= 0 || width > 300 || height <= 0 || height > 300) {
        printf("Error: Operation file corrupted\n");
        fclose(file);
        return 1;
    }
    initialize_drawing(&drawing, width, height, bg_char);

	int	r_value;
    char type;
    float x, y, w, h;
    char ch;
    while ((r_value = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &w, &h, &ch)) == 6) {
        if ((type != 'R' && type != 'r') || w <= 0 || h <= 0) {
            printf("Error: Operation file corrupted\n");
            fclose(file);
            return 1;
        }
        draw_rectangle(&drawing, type, x, y, w, h, ch);
    }
    if (r_value == -1)
		print_drawing(&drawing);
	else
		printf("Error: Operation file corrupted\n");
    fclose(file);
    return 0;
}
