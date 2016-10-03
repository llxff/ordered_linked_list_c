#include <stdlib.h>

#include "expect.h"
#include "ollist.h"

void test_ollist_new_list() {
  OLList *list = ollist_new_list();

  expect_to_be_true("ollist_new_list new should init list with zero length", list->length == 0);
  expect_to_be_true("ollist_new_list new should init list with nullify head", list->head == NULL);
}

void test_ollist_new_entry() {
  int value = 80;
  OLLEntry *entry = ollist_new_entry(value);

  expect_to_be_true("ollist_new_entry should init value", entry->value == value);
}

void test_ollist_new_default_next() {
  OLLEntry *entry = ollist_new_entry(10);

  expect_to_be_true("ollist_new should have nullify next", entry->next == NULL);
}

void test_ollist_append_entry() {
  OLList *list = ollist_new_list();
  OLLEntry *entry = ollist_new_entry(15);

  ollist_append(list, entry);

  expect_to_be_true("ollist_append should increment length", list->length == 1);
  expect_to_be_true("ollist_append should define head", list->head == entry);
}

void test_ollist_append_entry_twice() {
  OLList *list = ollist_new_list();
  OLLEntry *entry1 = ollist_new_entry(10);
  OLLEntry *entry2 = ollist_new_entry(11);
  OLLEntry *entry3 = ollist_new_entry(12);
  OLLEntry *entry4 = ollist_new_entry(13);

  ollist_append(list, entry1);
  ollist_append(list, entry2);
  ollist_append(list, entry3);
  ollist_append(list, entry4);

  expect_to_be_true("ollist_append should set length to 4", list->length == 4);
  expect_to_be_true("ollist_append should set entry1 as head", list->head == entry1);
  expect_to_be_true("ollist_append should set entry2 as next element", list->head->next == entry2);
  expect_to_be_true("ollist_append should set entry3 as next element", list->head->next->next == entry3);
  expect_to_be_true("ollist_append should set entry4 as next element", list->head->next->next->next == entry4);
}

void test_ollist_append_entry_and_sort() {
  OLList *list = ollist_new_list();
  OLLEntry *entry1 = ollist_new_entry(15);
  OLLEntry *entry2 = ollist_new_entry(10);

  ollist_append(list, entry1);
  ollist_append(list, entry2);

  expect_to_be_true("ollist_append should set entry2 as head", list->head == entry2);
  expect_to_be_true("ollist_append should set entry1 as next element", list->head->next == entry1);
}

void test_ollist_append_entry_and_sort_multiple() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(15);
  OLLEntry *entry3 = ollist_new_entry(19);
  OLLEntry *entry4 = ollist_new_entry(4);

  ollist_append(list, entry1);
  ollist_append(list, entry2);
  ollist_append(list, entry3);
  ollist_append(list, entry4);

  expect_to_be_true("ollist_append length", list->length == 4);
  expect_to_be_true("ollist_append 1", list->head == entry1);
  expect_to_be_true("ollist_append 2", list->head->next == entry4);
  expect_to_be_true("ollist_append 3", list->head->next->next == entry2);
  expect_to_be_true("ollist_append 4", list->head->next->next->next == entry3);
}

int main(int argc, char *argv[])
{
  test_ollist_new_list();
  test_ollist_new_entry();
  test_ollist_new_default_next();
  test_ollist_append_entry();
  test_ollist_append_entry_twice();
  test_ollist_append_entry_and_sort();
  test_ollist_append_entry_and_sort_multiple();

  return 0;
}
