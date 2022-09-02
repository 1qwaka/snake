#ifndef _UTILS_H_
#define _UTILS_H_

#include <sys/time.h>
#include "err_code.h"

typedef struct 
{
    int x, y;
} point_t;

err_code_t get_term_size(int *width, int *height);

void make_stdin_nonblock(void);

unsigned microsec_elapsed(struct timeval *start, struct timeval *end);

#endif