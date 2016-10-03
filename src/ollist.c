#include <stdlib.h>

#include "ollist.h"

OLList *ollist_new_list() {
  OLList *new_list = malloc(sizeof(OLList));

  new_list->head = NULL;
  new_list->length = 0;

  return new_list;
}

OLLEntry *ollist_new_entry(int value)
{
  OLLEntry *new_entry = malloc(sizeof(OLLEntry));

  new_entry->next = NULL;
  new_entry->value = value;

  return new_entry;
}

void ollist_append(OLList *list, OLLEntry *entry) {
  list->length++;

  if(list->head == NULL) {
    list->head = entry;
  }
  else {
    OLLEntry *next = list->head;

    while(next != NULL) {
      if(next->next == NULL) {
        next->next = entry;
        next = entry->next;
      }
      else {
        next = next->next;
      }
    }
  }
}
