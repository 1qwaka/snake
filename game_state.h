#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include <stdbool.h>
#include "game_types.h"
#include "snake.h"
#include "field.h"
#include "apple.h"

typedef enum game_status 
{
    GS_MENU,
    GS_RUNNING,
    GS_PAUSE,
} game_status_t;

struct game_state
{
    snake_t *snake;
    field_t *field;
    apple_t *apple;
    game_status_t status;
    unsigned score;
    bool is_game_over;
};

// TODO: new and delete functions

#endif