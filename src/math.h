#ifndef __MATH__H__
#define __MATH__H__

struct vec2 {
	double x, y;
};

struct vec3 {
	double x, y, z;
};

struct transform {
	struct vec3 position;
	struct vec3 rotation;
	struct vec3 scale;
};

#endif //!__MATH__H__
