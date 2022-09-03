#ifndef _APPLE_H_
#define _APPLE_H_

#include "utils.h"
#include "err_code.h"
#include "field.h"
#include "snake.h"

typedef struct 
{
    int x, y;
} apple_t;

apple_t *new_apple(int x, int y);

void delete_apple(apple_t *apple);

void update_apple(apple_t *apple, field_t* field);

void draw_apple(apple_t* apple, field_t* field);

err_code_t spawn_new_apple(field_t* field, snake_t* snake);

#endif