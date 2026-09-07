#include "render.h"
#include <stddef.h>
#include <stdlib.h>

struct render_object {
	char character;
};

struct render_object_chain {
	struct render_object		object;
	size_t						id;
	struct render_object_chain *next;
} *render_objects;

void render_init(void) {
	render_objects = NULL;
}

size_t render_queue(struct render_object *object) {
	static size_t				id = 0;
	struct render_object_chain *new_objects;
	new_objects			= malloc(sizeof *new_objects);
	new_objects->object = *object;
	new_objects->id		= id++;
	new_objects->next	= render_objects;
	render_objects		= new_objects;
	return id;
}

struct render_object *get_object(size_t id) {
}

void render_unqueue(size_t id) {
}

void render_update(void) {
	/* absurd platform specific shenanigans. write it yourself idc */
}

void render_close(void) {
}
