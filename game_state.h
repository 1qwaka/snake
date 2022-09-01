#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "snake.h"
#include "field.h"
#include "apple.h"

typedef struct 
{
    snake_t *snake;
    field_t *field;
    apple_t *apple;
    int score;

} game_state_t;

enum game_status 
{
    GS_RUNNING,
    GS_PAUSE,
    GS_MENU
};

#endif