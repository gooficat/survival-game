#ifndef __RENDER__H__
#define __RENDER__H__

struct render_object;

void render_init(void);

void render_queue(struct render_object *object);

void render_update(void);

void render_close(void);

#endif //!__RENDER__H__
