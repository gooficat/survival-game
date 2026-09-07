#ifndef __INPUT__H__
#define __INPUT__H__

#include <stdbool.h>

enum scroll_state {
	SCROLL_INACTIVE,
	SCROLL_DOWN,
	SCROLL_UP,
};

extern struct input {
	bool			  keys[256];
	bool			  mbtns[5];
	enum scroll_state scroll;
	/*TODO gamepads
  double sticks[2][2]; // two axes
  bool gbtns[??];
  */
} input;

void input_init(void);
void input_update(void);
void input_close(void);

#endif //!__INPUT__H__
