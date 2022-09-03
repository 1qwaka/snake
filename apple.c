#include <sys/random.h>
#include <stdio.h>
#include "apple.h"

apple_t *new_apple(int x, int y)
{
    apple_t *apple = malloc(sizeof(apple_t));
    apple->x = x;
    apple->y = y;
    return apple;
}

void draw_apple(apple_t* apple, field_t* field)
{
    if (apple->x < 0 || apple->y < 0)
        return;
    GET_CELL(field->game_panel, field->game_width, apple->y, apple->x) = '@';
}

void update_apple(apple_t *apple, field_t* field)
{
    if (apple-> x < 0 || apple->y < 0)
    {
        // printf("%lf\n", (double)rand() / RAND_MAX);
        apple->x = (int)(((double)rand() / RAND_MAX) * (field->game_width - FIELD_BORDER_SIZE * 2) + FIELD_BORDER_SIZE);
        apple->y = (int)(((double)rand() / RAND_MAX) * (field->game_height - FIELD_BORDER_SIZE * 2) + FIELD_BORDER_SIZE);
        // printf("%d %d\n", apple->x, apple->y);
    }
}
