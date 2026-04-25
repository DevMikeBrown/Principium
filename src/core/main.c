#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void play();

int main(int argc, char *argv[]) {
  printf("Executing Program...\n");

  start();
  load();
  play();
  end();

  return EXIT_SUCCESS;
}

