#include "utils.h"
#include "field.h"

field_t *create_new_field()
{
    field_t *game_field = malloc(sizeof(field_t));
    int width, height;
    get_term_size(&width, &height);
    
}