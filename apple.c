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

void delete_apple(apple_t *apple)
{
    free(apple);
}

void draw_apple(apple_t* apple, field_t* field)
{
    if (apple->x < 0 || apple->y < 0)
        return;
    GET_CELL(field->game_panel, field->game_width, apple->y, apple->x) = ACT_APPLE;
}

void update_apple(game_state_t *state)
{
    if (state->apple->x < 0 || state->apple->y < 0)
    {
        field_t *f = state->field;
        size_t b = f->border_size;
        set_random_apple_pos(state->apple, b, f->game_width - b, b, f->game_height - b);
    }
}

err_code_t set_random_apple_pos(apple_t *apple, int min_x, int max_x, int min_y, int max_y)
{
    apple->x = (int)(drand48() * (max_x - min_x) + min_x);
    apple->y = (int)(drand48() * (max_y - min_y) + min_y);
    
    return EC_OK;
}