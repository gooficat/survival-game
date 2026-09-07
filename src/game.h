#ifndef __GAME__H__
#define __GAME__H__

enum game_state_state {
	GAME_STATE_MAIN_MENU,
	GAME_STATE_RUNNING,
	GAME_STATE_PAUSED,
	GAME_STATE_EXITING,
};

extern struct game_state {
	double				  target_frame_time;
	double				  frame_start_time;
	double				  delta_time;
	enum game_state_state state;
} game_state;

#endif //!__GAME__H__
