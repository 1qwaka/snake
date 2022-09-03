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

#define FPS 10
#define MICROSEC_FRAME_TIME 1000000 / FPS

unsigned long long frame = 0;
game_state_t game_state = { 0 };


err_code_t init_game()
{
    // creating game field
    int width, height;
    get_term_size(&width, &height);
    game_state.field = new_field(width, height);
    reset_field(game_state.field);

    // creating snake
    game_state.snake = new_snake(5);
    game_state.snake->head_x = 15; //width / 2;
    game_state.snake->head_y = 10; //height / 2;

    // creatng apple
    game_state.apple = new_apple(10, 10);

    return EC_OK;
}

err_code_t update_game()
{
    // reset game field
    reset_field(game_state.field);

    // input handlers
    handle_input(&game_state);


    // update game objects
    update_snake(game_state.snake);
    update_apple(game_state.apple, game_state.field);

    printf("apple x:%d  y:%d\n", game_state.apple->x, game_state.apple->y);
    printf("snake x:%d  y:%d\n", game_state.snake->head_x, game_state.snake->head_y);
    if (game_state.apple->x == game_state.snake->head_x && 
        game_state.apple->y == game_state.snake->head_y)
        {
            grow_snake(game_state.snake);
            game_state.apple->x = -1;
        }
    

    // draw snake on field
    draw_snake(game_state.snake, game_state.field);
    // draw apple on field
    draw_apple(game_state.apple, game_state.field);
    // draw status panel 
    // ..

    // final draw field in console 
    draw_field(game_state.field);

    return EC_OK;
}

err_code_t mainloop()
{
    err_code_t exit_code = EC_OK;
    struct timeval frame_start, frame_end;
    unsigned frame_time;

    while (exit_code == EC_OK)
    {
        gettimeofday(&frame_start, NULL);
        exit_code = update_game();
        gettimeofday(&frame_end, NULL);

        frame_time = microsec_elapsed(&frame_start, &frame_end);
        if (frame_time < MICROSEC_FRAME_TIME)
            usleep(MICROSEC_FRAME_TIME - frame_time);

        frame++;
    }

    return exit_code;
}

int main(void)
{
    system("stty -icanon -echo");
    make_stdin_nonblock();

    err_code_t exit_code = EC_OK;
    exit_code = init_game();
    if (exit_code == EC_OK)
        exit_code = mainloop();

    return exit_code;
}
