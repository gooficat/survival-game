#ifndef __RENDER__H__
#define __RENDER__H__

#include <stddef.h>
struct render_object;

void render_init(void);

size_t				  render_queue(struct render_object *);
struct render_object *get_object(size_t);
void				  render_unqueue(size_t);

void render_update(void);

void render_close(void);

#endif //!__RENDER__H__
