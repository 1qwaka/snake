#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "snake.h"
#include "field.h"
#include "apple.h"

typedef enum game_status 
{
    GS_RUNNING,
    GS_PAUSE,
    GS_MENU
} game_status_t;

typedef struct 
{
    snake_t *snake;
    field_t *field;
    apple_t *apple;
    game_status_t status;
    int score;
} game_state_t;

#endif