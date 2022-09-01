#ifndef _UTILS_H_
#define _UTILS_H_

#include "err_codes.h"

typedef struct 
{
    int x, y;
} point_t;

err_code_t get_term_size(int *width, int *height);

void make_stdin_nonblock();

#endif