#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "err_code.h"
#include "utils.h"

err_code_t get_term_size(int *width, int *height)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    *width = w.ws_col;
    *height = w.ws_row;
    
    return EC_OK;
}

void make_stdin_nonblock(void)
{
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

unsigned microsec_elapsed(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) * 1000000 + end->tv_usec - start->tv_usec;
}
