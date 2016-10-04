#ifndef TASK_OLL_H
#define TASK_OLL_H

typedef struct _OLList OLList;
typedef struct _OLLEntry OLLEntry;

struct _OLList {
  OLLEntry *head;

  int length;
};

struct _OLLEntry {
  OLLEntry *next;

  int value;
};

OLList *ollist_new_list();

OLLEntry *ollist_new_entry(int value);

void ollist_inspect(OLList *list);

void ollist_append(OLList *head, OLLEntry *entry);

OLLEntry *_ollist_calculate_head_and_append(OLLEntry *current_head, OLLEntry *candidate);

void _ollist_insert_entry(OLLEntry *prev, OLLEntry *next, OLLEntry *candidate);

#endif
