#include "render.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
RenderTaskArray rrr;

bool render_queue(RenderTask *rend) {
  rrr.tasks[rrr.number_of_tasks] = *rend;
  if (rrr.tasks[rrr.number_of_tasks].real == 0) {
    printf("The New task is not real\n");
    return false;
  }
  rrr.number_of_tasks++;
  printf("rrr has %d amount of tasks\n", rrr.number_of_tasks);
  return true;
}

int compare(const void *a, const void *b) {
  const RenderTask *ia = a;
  const RenderTask *ib = b;

  if (ia->priority < ib->priority) return -1; 
  if (ia->priority > ib->priority) return 1;
  return 0;
}

void sort_rend_queue(){
  qsort(rrr.tasks, rrr.number_of_tasks, sizeof(RenderTask), compare);
}

void render() {
BeginDrawing();
  for (int i = 0; i < rrr.number_of_tasks; i++) {
    rrr.tasks[i].rendering_function();
  }
EndDrawing();
}
