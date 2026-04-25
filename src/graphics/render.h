typedef struct {
  int priority;
  void (*rendering_function)(void);
  int real;
} RenderTask;

typedef struct {
  RenderTask *tasks; // Please use calloc
  int number_of_tasks;
} RenderTaskArray;

#ifndef RENDER_H
#define RENDER_H

extern RenderTaskArray rrr;

#endif

bool render_queue(RenderTask *);
void sort_rend_queue();
void render();
