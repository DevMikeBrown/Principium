#include "game.h"
#include <raylib.h>

#ifndef STATS
#define STATS

typedef struct {
  char* data;
  int lvl;
} Stat;

typedef struct {
  Stat* info;
  int amount;
  float font_size;
  Color text_color;
} Statsheet;

#endif // !STATS

#ifndef STATSHEET
#define STATSHEET

extern Statsheet statistics;

#endif // !STATSHEET

void create_stat();
void organize_stats();
void add_stats_to_queue();
bool add_stat(Stat*);
