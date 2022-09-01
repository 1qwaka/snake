#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"

// TODO: handle terminal resize event
// #include <signal.h>

int main(void)
{

    char c = getchar();
    printf("%d %c\n", c, c);

    return 0;
}
