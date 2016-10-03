#include <stdio.h>

#include "expect.h"

void _expect_to_be_true(char caption[], int condition, int line) {
  if(condition) {
    printf("\033[0;32m");
  }
  else {
    printf("[%d] ", line);
    printf("\033[0;31m");
  }

  printf("%s", caption);
  printf("\033[0m\n");
}
