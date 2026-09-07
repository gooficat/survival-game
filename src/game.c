#include "game.h"
#include "time.h"

struct game_state game_state;

void start_frame(void) {
	game_state.frame_start_time = get_ms();
}

void update(void) {
}

void end_frame(void) {
	game_state.delta_time = get_ms() - game_state.frame_start_time;
}

void _start(void) {
	game_state.state			 = GAME_STATE_MAIN_MENU;
	game_state.target_frame_time = 1000.0 / 60.0;
	game_state.delta_time		 = 0;

	while (game_state.state != GAME_STATE_EXITING) {
		start_frame();
		update();
		end_frame();
	}
}
