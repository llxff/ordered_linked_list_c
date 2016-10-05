#include <stdlib.h>
#include <stdio.h>

#include "ollist.h"

OLList *ollist_new_list() {
  OLList *new_list = malloc(sizeof(OLList));

  new_list->head = NULL;
  new_list->length = 0;

  return new_list;
}

OLLEntry *ollist_new_entry(int value) {
  OLLEntry *new_entry = malloc(sizeof(OLLEntry));

  new_entry->next = NULL;
  new_entry->value = value;

  return new_entry;
}

void ollist_inspect(OLList *list) {
  printf("List length is: %d\n", list->length);

  OLLEntry *entry = list->head;

  printf("[");

  while(entry != NULL) {
    printf("%d", entry->value);
    entry = entry->next;

    if(entry != NULL) {
      printf(",");
    }
  }

  printf("]\n");
}

void ollist_append(OLList *list, OLLEntry *entry) {
  list->length++;
  list->head = _ollist_calculate_head_and_append(list->head, entry);
}

OLLEntry *_ollist_calculate_head_and_append(OLLEntry *current_head, OLLEntry *candidate) {
  if (current_head == NULL) return candidate;

  if(current_head->value >= candidate->value) {
    candidate->next = current_head;
    return candidate;
  }

  _ollist_insert_entry(current_head, current_head->next, candidate);

  return current_head;
}

void _ollist_insert_entry(OLLEntry *prev, OLLEntry *next, OLLEntry *candidate) {
  if(next == NULL) {
    prev->next = candidate;
  }
  else {
    if(next->value >= candidate->value) {
      prev->next = candidate;
      candidate->next = next;
    }
    else {
      _ollist_insert_entry(next, next->next, candidate);
    }
  }
}

OLLEntry *ollist_search(OLList *list, int guess) {
  OLLEntry *entry = list->head;

  while(entry != NULL) {
    if(entry->value == guess) {
      return entry;
    }

    entry = entry->next;
  }

  return NULL;
}

void ollist_remove(OLList *list, OLLEntry *guess) {
  if(list->head == NULL) return;

  if(list->head == guess) {
    ollist_shift(list);
  }
  else {
    OLLEntry *entry = list->head;
    OLLEntry *next = entry->next;

    while(next != NULL) {
      if(next == guess) {
        entry->next = guess->next;
        list->length--;
        guess->next = NULL;
        next = NULL;
      }
      else {
        entry = next;
        next = next->next;
      }
    }
  }
}

OLLEntry *ollist_shift(OLList *list) {
  if(list->head == NULL) return NULL;

  OLLEntry *head = list->head;

  list->length--;
  list->head = head->next;
  head->next = NULL;

  return head;
}
