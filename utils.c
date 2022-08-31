#include <sys/ioctl.h>
#include "err_codes.h"

int get_term_size(int *width, int *height)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    *width = w.ws_col;
    *height = w.ws_row;
    
    return OK;
}