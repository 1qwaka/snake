#ifndef _FIELD_H_
#define _FIELD_H_

#include <stdlib.h>
#include "field.h"

#define FIELD_BORDER_SIZE   1
#define STATUS_PANEL_HEIGHT 1

typedef struct 
{
    size_t game_width, game_height;
    size_t panel_width, panel_height;
    size_t width, height;
    char **game_panel;
    char **stats_panel;
    char **field;
    size_t border_size;
} field_t;

field_t *new_field(int width, int height);

void delete_field(field_t *field);

// int resize_field(field_t* field, int new_width, int new_height);

#endif