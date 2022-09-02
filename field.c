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
    for (int i = (int)field->height - 1; i > -1; i--)
    {
        for (int j = (int)field->width - 1; j > -1; j--)
            printf("%c", field->field[_idx(field->width, i, j)]);
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
    {
        field->game_panel[_idx(field->game_width, 0, i)] = CT_UPSIDE;
        field->game_panel[_idx(field->game_width, field->game_height - 1, i)] = CT_UPSIDE;
    }

    for (size_t i = 0; i < field->game_height; i++)
    {
        field->game_panel[_idx(field->game_width, i, 0)] = CT_SIDE;
        field->game_panel[_idx(field->game_width, i, field->game_width - 1)] = CT_SIDE;
    }
}