#ifndef _FIELD_H_
#define _FIELD_H_

#include <stdlib.h>
#include <wchar.h>
#include "game_types.h"

#define FIELD_BORDER_SIZE   1
#define STATUS_PANEL_HEIGHT 2

#define _IDX(width, i, j) ((i) * (width) + (j))
// macro to work with one dimensional array like with two dimensional array
#define GET_CELL(array, width, i, j) ((array)[_IDX(width, i, j)])


struct field
{
    size_t game_width, game_height;
    size_t panel_width, panel_height;
    size_t width, height;
    char *game_panel;
    char *stats_panel;
    char *field;
    size_t border_size;
};

enum field_cell_types
{
    FCT_EMPTY = ' ',
    FCT_SIDE = '|',
    FCT_UPSIDE = '-',
};

field_t *new_field(int width, int height);

void delete_field(field_t *field);

void draw_field(field_t *field);

void set_empty_field(field_t *field);

void reset_field(field_t *field);

void set_game_panel_borders(field_t *field);

// int resize_field(field_t* field, int new_width, int new_height);

#endif