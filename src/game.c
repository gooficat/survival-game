#include "game.h"

struct game_state game_state;

void _start(void) {
	game_state.state			 = GAME_STATE_MAIN_MENU;
	game_state.target_frame_time = 60.0 / 1000.0;
}
