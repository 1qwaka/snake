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

snake_t* new_snake(size_t max_length);

void delete_snake(snake_t *snake);

err_code_t draw_snake(snake_t *snake, field_t *field);

void update_snake(snake_t *snake);

void grow_snake(snake_t *snake);

#endif