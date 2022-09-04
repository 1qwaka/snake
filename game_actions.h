#ifndef _GAME_ACTIONS_H_
#define _GAME_ACTIONS_H_

#include <stdbool.h>
#include "game_state.h"

bool apple_can_be_eaten(game_state_t *state);

void try_eat_apple(game_state_t *state);

void draw_score(game_state_t *state);

void check_game_over(game_state_t *state);

#endif  // _GAME_ACTIONS_H_