#include <stdlib.h>

typedef struct 
{
    size_t field_width, field_height;
    size_t panel_width, panel_height;
    char **game_field;
    char **stats_panel;
} field_t;