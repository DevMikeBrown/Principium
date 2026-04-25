#include <stdio.h>
#include "circle.h"
#include <raylib.h>

void circle_rend();

void circle() {
  RenderTask circle = {.priority = 1, .rendering_function = circle_rend, .real = 1};
  printf("Created Circle Task\n");
  if(!render_queue(&circle)){
    perror("adding circle to render queue failed\n");
  }
  printf("Queued up Circle task\n");
}

void circle_rend() {
  printf("Drawing Background White\n");
  ClearBackground(WHITE);
  printf("Drawing Circle\n");
  DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 32, RED);
}
