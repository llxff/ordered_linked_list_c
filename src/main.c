#include <stdio.h>

#include "ollist.h"

int main(int argc, char *argv[])
{
  OLList *list = ollist_new_list();

  ollist_append(list, ollist_new_entry(4));
  ollist_append(list, ollist_new_entry(2));
  ollist_append(list, ollist_new_entry(5));
  ollist_append(list, ollist_new_entry(6));
  ollist_append(list, ollist_new_entry(1));
  ollist_append(list, ollist_new_entry(3));

  ollist_inspect(list);

  return 0;
}
