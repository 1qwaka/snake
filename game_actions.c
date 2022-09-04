#include <stdio.h>
#include "game_actions.h"

bool apple_can_be_eaten(game_state_t *state)
{
    return state->apple->x == state->snake->head_x && 
           state->apple->y == state->snake->head_y;
}

void try_eat_apple(game_state_t *state)
{
    if (apple_can_be_eaten(state))
    {
        grow_snake(state->snake);
        state->apple->x = state->apple->y = -1;
        state->score++;
    }
}

void draw_score(game_state_t *state)
{
    field_t *field = state->field;
    snprintf(field->stats_panel, field->panel_width, "score: %u", state->score);
    for (size_t i = 0; i < field->panel_width; i++)
        if (field->stats_panel[i] == 0)
        {
            field->stats_panel[i] = FCT_EMPTY;
            break;
        } 
}

void check_game_over(game_state_t *state)
{
    snake_t *s = state->snake;
    field_t *f = state->field;
    int border = FIELD_BORDER_SIZE;

    state->is_game_over = s->head_x <= border - 1 || s->head_x >= (int)f->game_width - border ||
                          s->head_y <= border - 1 || s->head_y >= (int)f->game_height - border;
}
