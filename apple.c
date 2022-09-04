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
    GET_CELL(field->game_panel, field->game_width, apple->y, apple->x) = ACT_APPLE;
}

void update_apple(game_state_t *state)
{
    if (state->apple->x < 0 || state->apple->y < 0)
    {
        set_random_apple_pos(state);
    }
}

err_code_t set_random_apple_pos(game_state_t *state)
{
    int border = FIELD_BORDER_SIZE;
    field_t *field = state->field;
    apple_t *apple = state->apple;
    
    apple->x = (int)(drand48() * (field->game_width - border * 2) + border);
    apple->y = (int)(drand48() * (field->game_height - border * 2) + border);
    
    return EC_OK;
}