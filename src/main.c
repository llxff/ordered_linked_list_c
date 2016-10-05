#include <stdio.h>
#include <string.h>

#include "ollist.h"

const char *SEARCH_COMMAND = "s";
const char *REMOVE_COMMAND = "r";
const char *ADD_COMMAND = "a";

void print(int value, char *string) {
  printf("\033[0;33m%d %s\033[0m\n", value, string);
}

void add_command(OLList *list, int value) {
  ollist_append(list, ollist_new_entry(value));
  ollist_inspect(list);

  printf("\n");
}

void search_command(OLList *list, int guess) {
  if(ollist_search(list, guess)) {
    print(guess, "was found in list");
  }
  else {
    print(guess, "was not found in list");
  }

  printf("\n");
}

void remove_command(OLList *list, int guess) {
  OLLEntry *entry = ollist_search(list, guess);

  if(entry) {
    ollist_remove(list, entry);
    print(guess, "was removed");
    ollist_inspect(list);
  }
  else {
    print(guess, "was not found in list");
  }

  printf("\n");
}

int main(int argc, char *argv[])
{
  printf("\033[0;33m%s X add X value to the list\033[0m\n", ADD_COMMAND);
  printf("\033[0;33m%s X will search X value\033[0m\n", SEARCH_COMMAND);
  printf("\033[0;33m%s X will remove X value\033[0m\n", REMOVE_COMMAND);
  printf("\033[0;33mCtrl + C for exit\033[0m\n\n");

  OLList *list = ollist_new_list();
  ollist_inspect(list);
  printf("\n");

  while(1) {
    char *command[1];
    int value;

    printf("\033[1;33m> ");

    scanf("%s %d", command, &value);

    printf("\033[0m");

    if(strcmp(command, ADD_COMMAND) == 0) {
      add_command(list, value);
    }
    else if(strcmp(command, SEARCH_COMMAND) == 0) {
      search_command(list, value);
    }
    else if(strcmp(command, REMOVE_COMMAND) == 0) {
      remove_command(list, value);
    }
    else {
      printf("unrecognized command [%s]\n", command);
      printf("\n");
    }
  }

  return 0;
}
