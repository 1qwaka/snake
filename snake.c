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
    GET_CELL(field->game_panel, field->game_width, snake->head_y, snake->head_x) = 'S';

    for (size_t i = 0; i < snake->length; i++)
    {
        GET_CELL(field->game_panel, field->game_width, snake->body[i].y, snake->body[i].x) = 's';
    }

    return EC_OK;
}

void update_snake(snake_t *snake)
{
    if (snake->length > 0)
    {
        snake->tail_prev_pos.x = snake->body[snake->length - 1].x;
        snake->tail_prev_pos.y = snake->body[snake->length - 1].y;
    }
    else
    {
        snake->tail_prev_pos.x = snake->head_x;
        snake->tail_prev_pos.y = snake->head_y;
    }

    int x = snake->head_x;
    int y = snake->head_y;
    int tmp_x, tmp_y;

    snake->head_x += snake->direction.x;
    snake->head_y += snake->direction.y;

    for (size_t i = 0; i < snake->length; i++)
    {
        tmp_x = snake->body[i].x;
        tmp_y = snake->body[i].y;
        snake->body[i].x = x;
        snake->body[i].y = y;
        x = tmp_x;
        y = tmp_y;
    }
}

void grow_snake(snake_t *snake)
{
    snake->length++;
    snake->body[snake->length - 1].x = snake->tail_prev_pos.x;
    snake->body[snake->length - 1].y = snake->tail_prev_pos.y;
}