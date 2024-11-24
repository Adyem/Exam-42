#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define ERR_ARG "Error: argument\n"
#define ERR_FILE "Error: Operation file corrupted\n"

typedef struct {
    int width;
    int height;
    char bg_char;
    char **canvas;
} Canvas;

typedef struct {
    char type;
    float x;
    float y;
    float radius;
    char ch;
} Circle;

void free_canvas(Canvas *canvas) {
    for (int i = 0; i < canvas->height; i++) {
        free(canvas->canvas[i]);
    }
    free(canvas->canvas);
}

int init_canvas(Canvas *canvas, int width, int height, char bg_char) {
    canvas->width = width;
    canvas->height = height;
    canvas->bg_char = bg_char;
    canvas->canvas = malloc(sizeof(char*) * height);
    if (!canvas->canvas) return 0;

    for (int i = 0; i < height; i++) {
        canvas->canvas[i] = malloc(sizeof(char) * width);
        if (!canvas->canvas[i]) return 0;
        memset(canvas->canvas[i], bg_char, width);
    }
    return 1;
}

void print_canvas(Canvas *canvas) {
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            putchar(canvas->canvas[i][j]);
        }
        putchar('\n');
    }
}

void draw_circle(Canvas *canvas, Circle *circle) {
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            // Calculate the square of the distance to avoid using sqrt
            float dist_sq = powf(j - circle->x, 2) + powf(i - circle->y, 2);
            float radius_sq = powf(circle->radius, 2);

            if (circle->type == 'C' && dist_sq <= radius_sq)
                canvas->canvas[i][j] = circle->ch;
            else if (circle->type == 'c' && (radius_sq - 1 < dist_sq && dist_sq < radius_sq + 1))
                canvas->canvas[i][j] = circle->ch;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, ERR_ARG, strlen(ERR_ARG));
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        write(1, ERR_FILE, strlen(ERR_FILE));
        return 1;
    }

    Canvas canvas;
    int width, height;
    char bg_char;

    if (fscanf(file, "%d %d %c\n", &width, &height, &bg_char) != 3) {
        write(1, ERR_FILE, strlen(ERR_FILE));
        fclose(file);
        return 1;
    }

    if (!init_canvas(&canvas, width, height, bg_char)) {
        write(1, ERR_FILE, strlen(ERR_FILE));
        fclose(file);
        return 1;
    }

    Circle circle;
    while (fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.ch) == 5)
	{
        if (circle.type != 'C' && circle.type != 'c')
		{
            free_canvas(&canvas);
            fclose(file);
            write(1, ERR_FILE, strlen(ERR_FILE));
            return 1;
        }
        draw_circle(&canvas, &circle);
    }
    print_canvas(&canvas);
    free_canvas(&canvas);
    fclose(file);
    return 0;
}
