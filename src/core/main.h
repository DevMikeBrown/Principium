#include "game.h"
#include <raylib.h>

void play() {
  while (!WindowShouldClose()) {
    update();
  }
}
