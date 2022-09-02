#ifndef _FIELD_H_
#define _FIELD_H_

#include <stdlib.h>

#define FIELD_BORDER_SIZE   1
#define STATUS_PANEL_HEIGHT 1

#define _idx(width, i, j) ((i) * (width) + (j))

typedef struct 
{
    size_t game_width, game_height;
    size_t panel_width, panel_height;
    size_t width, height;
    char *game_panel;
    char *stats_panel;
    char *field;
    size_t border_size;
} field_t;

enum field_cell_types
{
    CT_EMPTY = ' ',
    CT_SIDE = '#',
    CT_UPSIDE = '#',
};

field_t *new_field(int width, int height);

void delete_field(field_t *field);

void draw_field(field_t *field);

void set_empty_field(field_t *field);

void reset_field(field_t *field);

void set_game_panel_borders(field_t *field);

// int resize_field(field_t* field, int new_width, int new_height);

#endif