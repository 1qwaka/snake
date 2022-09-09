#ifndef _APPLE_H_
#define _APPLE_H_

#include "game_types.h"
#include "utils.h"
#include "err_code.h"
#include "field.h"
#include "snake.h"
#include "game_state.h"

struct apple
{
    int x, y;
};

enum apple_cell_types
{
    ACT_APPLE = '@'
};

apple_t *new_apple(int x, int y);

void *del_apple(apple_t *apple);

void delete_apple(apple_t *apple);

void update_apple(game_state_t *state);

void draw_apple(apple_t* apple, field_t* field);

err_code_t set_random_apple_pos(game_state_t *state);

#endif