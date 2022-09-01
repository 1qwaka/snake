#include <sys/ioctl.h>
#include "err_codes.h"
#include "utils.h"

err_code_t get_term_size(int *width, int *height)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    *width = w.ws_col;
    *height = w.ws_row;
    
    return EC_OK;
}

void make_stdin_nonblock();
