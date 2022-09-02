#include <stdio.h>
#include <string.h>
#include "input_handler.h"
#include "snake.h"

void handle_input(game_state_t *state)
{
    char buf[256] = { 0 };
    fgets(buf, sizeof(buf), stdin);

    if (strlen(buf) < 2)
        return;
    
    char command = buf[strlen(buf) - 2];
    snake_t *snake = state->snake;

    switch (command)
    {
    case ak_up:
    {
        if (snake->direction.y == 0)
        {
            snake->direction.x = 0;
            snake->direction.y = 1;
        }
        break;
    }
    
    case ak_down:
    {
        if (snake->direction.y == 0)
        {
            snake->direction.x = 0;
            snake->direction.y = -1;
        }
        break;
    }

    case ak_left:
    {
        if (snake->direction.x == 0)
        {
            snake->direction.x = -1;
            snake->direction.y = 0;
        }
        break;
    }

    case ak_right:
    {
        if (snake->direction.x == 0)
        {
            snake->direction.x = 1;
            snake->direction.y = 0;
        }
        break;
    }

    // TODO
    case ak_pause:
    case ak_exit:
    default:
        break;
    }

}