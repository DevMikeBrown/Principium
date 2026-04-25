#ifndef RENDERTASK_H
#define RENDERTASK_H
typedef struct {
  int priority;
  void (*rendering_function)(void);
  int real;
} RenderTask;

#endif // !RENDERTASK_H

#ifndef RENDERTASKARRAY_H
#define RENDERTASKARRAY_H
typedef struct {
  RenderTask *tasks; // Please use calloc
  int number_of_tasks;
} RenderTaskArray;
#endif

#ifndef RENDER_H
#define RENDER_H

extern RenderTaskArray rrr;

#endif

bool render_queue(RenderTask *);
void sort_rend_queue();
void render();
