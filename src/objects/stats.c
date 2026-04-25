#include "stats.h"
#include "render.h"
#include <raylib.h>
#include <stdlib.h>
Statsheet statistics;

void create_stat(){
  statistics.info = calloc(100, sizeof(Stat));
  statistics.amount = 0;
  statistics.font_size = 30; 
  statistics.text_color = LIGHTGRAY;
}

bool add_stat(Stat* the_stat){
  statistics.info[statistics.amount] = *the_stat;
  statistics.amount++;
  return true;
}

static int compare(const void *a, const void *b) {
  const Stat *ia = a;
  const Stat *ib = b;

  if (ia->lvl < ib->lvl) return -1; 
  if (ia->lvl > ib->lvl) return 1;
  return 0;
}

void organize_stats(){
  qsort(statistics.info, statistics.amount, sizeof(Stat), compare);
}

void draw_stats(){
  for (int i = 0; i < statistics.amount; i++) {
    DrawText(statistics.info[i].data, 0, i*31, statistics.font_size, statistics.text_color);
  }
}

void add_stats_to_queue(){
  RenderTask stats_bruh = {.priority = 3, .rendering_function = draw_stats, .real = 1};
  render_queue(&stats_bruh);
}
