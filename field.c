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

void delete_field(field_t *field)
{
    free(field->field);
    free(field);
}

void draw_field(field_t *field)
{
    // printf("\n");
    // drawing inverse to make coords start from bottom left and Y go upward
    for (int i = (int)field->height - 1; i > -1; i--)
    {
        for (int j = 0; j < (int)field->width; j++)
            // printf("%c", field->field[_idx(field->width, i, j)]);
            printf("%lc", GET_CELL(field->field, field->width, i, j));
        // to make mouse be on the last line of field, not the line after
        if (i != 0)
            printf("\n");
        fflush(stdout);
    }
}

void set_empty_field(field_t *field)
{
     for (size_t i = 0; i < field->height * field->width; i++)
        field->field[i] = FCT_EMPTY;
}

void reset_field(field_t *field)
{
   set_empty_field(field);
   set_game_panel_borders(field);
}

void set_game_panel_borders(field_t *field)
{
    char *gp = field->game_panel;
    size_t gp_width = field->game_width;
    size_t gp_height = field->game_height;

    for (size_t i = 0; i < gp_width; i++)
        for (int j = 0; j < FIELD_BORDER_SIZE; j++)
        {
            GET_CELL(gp, gp_width, j, i) = FCT_UPSIDE;
            GET_CELL(gp, gp_width, gp_height - 1 - j, i) = FCT_UPSIDE;
        }
        

    for (size_t i = 0; i < gp_height; i++)
        for (int j = 0; j < FIELD_BORDER_SIZE; j++)
        {
            GET_CELL(gp, gp_width, i, j) = FCT_SIDE;
            GET_CELL(gp, gp_width, i, gp_width - 1 - j) = FCT_SIDE;
        }
}