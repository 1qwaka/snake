#include <stdio.h>
#include "utils.h"
#include "field.h"

field_t *new_field(int width, int height)
{
    field_t *field = malloc(sizeof(field_t));

    field->width = width;
    field->height = height;
    field->field = malloc(width * height);

    field->panel_width = width;
    field->panel_height = STATUS_PANEL_HEIGHT;
    field->stats_panel = field->field;

    field->game_width = width;
    field->game_height = height - STATUS_PANEL_HEIGHT;
    field->game_panel = field->field + field->game_width * field->panel_height;

    field->border_size = FIELD_BORDER_SIZE;

    return field;
}

void delete_field(field_t *field);

void draw_field(field_t *field)
{
    // drawing inverse to make coords start from bottom left and Y go upward
    for (int i = (int)field->height - 1; i > -1; i--)
    {
        for (int j = 0; j < (int)field->width; j++)
            // printf("%c", field->field[_idx(field->width, i, j)]);
            printf("%c", GET_CELL(field->field, field->width, i, j));
        if (i != 0)
            printf("\n");
        fflush(stdout);
    }
}

void set_empty_field(field_t *field)
{
     for (size_t i = 0; i < field->height * field->width; i++)
        field->field[i] = CT_EMPTY;
}

void reset_field(field_t *field)
{
   set_empty_field(field);
   set_game_panel_borders(field);
}

void set_game_panel_borders(field_t *field)
{
    for (size_t i = 0; i < field->game_width; i++)
        for (int j = 0; j < FIELD_BORDER_SIZE; j++)
        {
            // field->game_panel[_idx(field->game_width, j, i)] = CT_UPSIDE;
            // field->game_panel[_idx(field->game_width, field->game_height - 1 - j, i)] = CT_UPSIDE;
            GET_CELL(field->game_panel, field->game_width, j, i) = CT_UPSIDE;
            GET_CELL(field->game_panel, field->game_width, field->game_height - 1 - j, i) = CT_UPSIDE;
        }
        

    for (size_t i = 0; i < field->game_height; i++)
        for (int j = 0; j < FIELD_BORDER_SIZE; j++)
        {
            GET_CELL(field->game_panel, field->game_width, i, j) = CT_SIDE;
            GET_CELL(field->game_panel, field->game_width, i, field->game_width - 1 - j) = CT_SIDE;
        }
}