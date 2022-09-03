#include "snake.h"
#include <stdio.h>

snake_t* new_snake(size_t max_length)
{
    snake_t *snake = malloc(sizeof(snake_t));
    snake->body = malloc(max_length * sizeof(*snake->body));
    snake->head_x = 0;
    snake->head_y = 0;
    snake->length = 0;
    snake->max_length = max_length;
    snake->direction = (point_t){ .x = 1, .y = 0 };
    
    return snake;
}

void delete_snake(snake_t *snake);

err_code_t draw_snake(snake_t *snake, field_t *field)
{
    GET_CELL(field->game_panel, field->game_width, snake->head_y, snake->head_x) = '+';

    for (size_t i = 0; i < snake->length; i++)
    {
        GET_CELL(field->game_panel, field->game_width, snake->body[i].x, snake->body[i].y) = '*';
    }

    return EC_OK;
}