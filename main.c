#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#include "utils.h"
#include "err_code.h"
#include "input_handler.h"
#include "apple.h"
#include "field.h"
#include "snake.h"
#include "game_state.h"

// TODO: handle terminal resize event
// #include <signal.h>

// TODO: change char to wchar
// #include <wchar.h>

// TODO: add colors support

#define FPS 2
#define MICROSEC_SLEEP_INTERVAL 1000000 / FPS

unsigned long long frame = 0;
game_state_t game_state;

err_code_t init_game()
{
    int width, height;
    get_term_size(&width, &height);
    game_state.field = new_field(width, height);
    reset_field(game_state.field);

    return EC_OK;
}

err_code_t update_game()
{
    draw_field(game_state.field);

    return EC_OK;
}

err_code_t mainloop()
{
    err_code_t exit_code = EC_OK;
    struct timeval start, end;
    unsigned frame_time;

    while (exit_code == EC_OK){

        gettimeofday(&start, NULL);
        exit_code = update_game();
        gettimeofday(&end, NULL);

        frame_time = microsec_elapsed(&start, &end);
        if (frame_time < MICROSEC_SLEEP_INTERVAL)
            usleep(MICROSEC_SLEEP_INTERVAL - frame_time);
        // printf("sleep for %d\n", MICROSEC_SLEEP_INTERVAL - frame_time);
        frame++;
    }

    return exit_code;
}

int main(void)
{
    // system("stty -echo");
    err_code_t exit_code = EC_OK;
    exit_code = init_game();
    if (exit_code == EC_OK)
        exit_code = mainloop();
    return exit_code;
}
