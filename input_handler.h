#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

#include "game_state.h"

enum action_key
{
    ak_up     = 'w',
    ak_left   = 'a',
    ak_down   = 's',
    ak_right  = 'd',
    ak_exit   = 'q', // TODO
    ak_pause  = 'e'  // TODO
};

void handle_input(game_state_t *state);

#endif