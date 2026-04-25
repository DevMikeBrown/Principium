#include <stdio.h>
#include "circle.h"
#include "stats.h"
#include <raylib.h>
#include <stdlib.h>

typedef struct {
  Vector2 position;
  float radius;
  Color color;
} CircluarObject;

CircluarObject Roundie = {{0, 0}, 32, RED};

void circle_rend();

void circle() {
  RenderTask circle = {.priority = 2, .rendering_function = circle_rend, .real = 1};
  printf("Created Circle Task\n");
  if(!render_queue(&circle)){
    perror("adding circle to render queue failed\n");
  }
  printf("Queued up Circle task\n");
  Roundie.position.x = (float)GetScreenWidth()/2; 
  Roundie.position.y = (float)GetScreenHeight()/2;
}
Stat* RoundiePos;
void circle_stat(){
  RoundiePos = (Stat*)malloc(sizeof(Stat));
  RoundiePos->lvl = 1;
  RoundiePos->lvl = 1;
  RoundiePos->data = malloc(sizeof(char)*50);
  RoundiePos->data = malloc(sizeof(char)*50);
  add_stat(RoundiePos);
}

void circle_clean(){
  free(RoundiePos);
}

void circle_cycle(){
  sprintf(RoundiePos->data, "Roundie's Position: (%f ; %f)", Roundie.position.x, Roundie.position.y);
}

void circle_move(){
  if (IsKeyDown(KEY_W)) {
    Roundie.position.y -= 1;
  }
  if (IsKeyDown(KEY_A)) {
    Roundie.position.x -= 1;
  }
  if (IsKeyDown(KEY_S)) {
    Roundie.position.y += 1;
  }
  if (IsKeyDown(KEY_D)) {
    Roundie.position.x += 1;
  }
};

void circle_rend() {
  printf("Drawing Circle\n");
  DrawCircleV(Roundie.position, Roundie.radius, Roundie.color);
}
