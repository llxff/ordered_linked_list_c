#include <stdio.h>

#include "ollist.h"

int main(int argc, char *argv[])
{
  OLLEntry *list = ollist_new(80);

  printf("%d\n", list->value);
  return 0;
}
