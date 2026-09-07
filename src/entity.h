#ifndef __ENTITY__H__
#define __ENTITY__H__

#include "math.h"
#include <stddef.h>

struct entity {
	struct transform transform;
	float			 health;
	int				 action;
	size_t			 model;
	size_t			 frame;
	size_t			 id;
};

#endif //!__ENTITY__H__
