#ifndef _SNAKE_H
#define _SNAKE_H

#include <stdlib.h>
#include "utils.h"
#include "err_code.h"
#include "field.h"

typedef struct
{
    int head_x, head_y;
    point_t *body;
    size_t length, max_length;
    point_t direction;
    point_t tail_prev_pos;
} snake_t;

enum SNAKE_CELL_TYPE
{
    SCT_HEAD = L'O',
    SCT_BODY = L'o'
};

/**
 * @brief creates new snake object and return pointer on it
 * 
 * @param max_length maximum length of snake array of characters 
 * of this size will be allocate
 * @return snake_t* new snake object
 */
snake_t* new_snake(size_t max_length);

void delete_snake(snake_t *snake);

err_code_t draw_snake(snake_t *snake, field_t *field);

void update_snake(snake_t *snake);

void grow_snake(snake_t *snake);

#endif