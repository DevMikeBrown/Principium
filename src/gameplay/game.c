#include "objects.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void start() {
  InitWindow(1200, 750, "My Raylib Game");
  printf("\nWindow Initialized\n");
  rrr.tasks = calloc(100, sizeof(RenderTask));
  if (rrr.tasks == NULL) {
    perror("\nFailed to allocate memory to rrr\n");
  }
  rrr.number_of_tasks = 0;
}

void load(){
  circle();
}

int num_of_tasks = 0;
void update() {
  if (rrr.number_of_tasks != num_of_tasks) {
    sort_rend_queue();
    num_of_tasks = rrr.number_of_tasks;
  }
  // Rendering Stage...
  render();
}
void end() {
  printf("\nEnding Program\n");
  free(rrr.tasks);
  CloseWindow();
}
