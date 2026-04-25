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
  create_stat();
  add_stats_to_queue();
  circle_stat();
  background();
}

int num_of_tasks = 0;
int num_of_stats = 0;
void update() {
  if (rrr.number_of_tasks != num_of_tasks) {
    sort_rend_queue();
    num_of_tasks = rrr.number_of_tasks;
  }

  if (statistics.amount != num_of_stats) {
    organize_stats();
    num_of_stats = statistics.amount;
  }
  circle_move();
  circle_cycle();

  // Rendering Stage...
  render();
}
void end() {
  printf("\nEnding Program\n");
  free(rrr.tasks);
  free(statistics.info);
  circle_clean();
  CloseWindow();
}
