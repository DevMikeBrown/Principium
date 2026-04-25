#include "background.h"
#include <raylib.h>

void draw_background();

void background(){
  RenderTask BG = {.priority = 1, .rendering_function = draw_background, .real = 1};
  render_queue(&BG);
}

void draw_background(){
  ClearBackground(WHITE);
}
