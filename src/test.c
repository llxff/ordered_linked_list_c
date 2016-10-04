#include <stdlib.h>

#include "expect.h"
#include "ollist.h"

void test_ollist_new_list() {
  OLList *list = ollist_new_list();

  expect_true("ollist_new_list new should init list with zero length", list->length == 0);
  expect_true("ollist_new_list new should init list with nullify head", list->head == NULL);
}

void test_ollist_new_entry() {
  int value = 80;
  OLLEntry *entry = ollist_new_entry(value);

  expect_true("ollist_new_entry should init value", entry->value == value);
}

void test_ollist_new_default_next() {
  OLLEntry *entry = ollist_new_entry(10);

  expect_true("ollist_new should have nullify next", entry->next == NULL);
}

void test_ollist_append_entry() {
  OLList *list = ollist_new_list();
  OLLEntry *entry = ollist_new_entry(15);

  ollist_append(list, entry);

  expect_true("ollist_append should increment length", list->length == 1);
  expect_true("ollist_append should define head", list->head == entry);
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

  expect_true("ollist_append should set length to 4", list->length == 4);
  expect_true("ollist_append should set entry1 as head", list->head == entry1);
  expect_true("ollist_append should set entry2 as next element", list->head->next == entry2);
  expect_true("ollist_append should set entry3 as next element", list->head->next->next == entry3);
  expect_true("ollist_append should set entry4 as next element", list->head->next->next->next == entry4);
}

void test_ollist_append_entry_and_sort() {
  OLList *list = ollist_new_list();
  OLLEntry *entry1 = ollist_new_entry(15);
  OLLEntry *entry2 = ollist_new_entry(10);

  ollist_append(list, entry1);
  ollist_append(list, entry2);

  expect_true("ollist_append should set entry2 as head", list->head == entry2);
  expect_true("ollist_append should set entry1 as next element", list->head->next == entry1);
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

  expect_true("ollist_append length", list->length == 4);
  expect_true("ollist_append 1", list->head == entry1);
  expect_true("ollist_append 2", list->head->next == entry4);
  expect_true("ollist_append 3", list->head->next->next == entry2);
  expect_true("ollist_append 4", list->head->next->next->next == entry3);
}

void test_ollist_search_empty_list() {
  OLList *list = ollist_new_list();

  expect_true("ollist_search should return NULL if list is empty", ollist_search(list, 5) == NULL);
}

void test_ollist_search_not_found() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);

  ollist_append(list, entry1);

  expect_true("ollist_search should return NULL if not found", ollist_search(list, 5) == NULL);
}

void test_ollist_search_with_one_item() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);

  ollist_append(list, entry1);

  expect_true("ollist_search should return finded entry", ollist_search(list, entry1->value) == entry1);
}

void test_ollist_search_with_several_items() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(6);

  ollist_append(list, entry1);
  ollist_append(list, entry2);

  expect_true("ollist_search should return finded entry2", ollist_search(list, entry2->value) == entry2);
}

void test_ollist_remove_from_empty_list() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);

  ollist_remove(list, entry1);

  expect_true("ollist_remove should not change head if it empty", list->head == NULL);
  expect_true("ollist_remove should not change length if it empty", list->length == 0);
}

void test_ollist_remove_from_list_with_single_item() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);

  ollist_append(list, entry1);

  ollist_remove(list, entry1);

  expect_true("ollist_remove should set head as NULL", list->head == NULL);
  expect_true("ollist_remove should set length as 0", list->length == 0);
}

void test_ollist_remove_from_end() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(4);

  ollist_append(list, entry1);
  ollist_append(list, entry2);

  ollist_remove(list, entry2);

  expect_true("ollist_remove should not change head", list->head == entry1);
  expect_true("ollist_remove should set length as 1", list->length == 1);
  expect_true("ollist_remove should detach entry2 from entry1", entry1->next == NULL);
}

void test_ollist_remove_from_middle() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(4);
  OLLEntry *entry3 = ollist_new_entry(5);

  ollist_append(list, entry1);
  ollist_append(list, entry2);
  ollist_append(list, entry3);

  ollist_remove(list, entry2);

  expect_true("ollist_remove should not change head", list->head == entry1);
  expect_true("ollist_remove should set length as 2", list->length == 2);
  expect_true("ollist_remove should link entry1 and entry3", entry1->next == entry3);
  expect_true("ollist_remove should detach entry2 from entry3", entry2->next == NULL);
  expect_true("ollist_remove should not change list items", ollist_search(list, entry3->value) == entry3);
}

void test_ollist_remove_from_beginning() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(4);
  OLLEntry *entry3 = ollist_new_entry(5);

  ollist_append(list, entry1);
  ollist_append(list, entry2);
  ollist_append(list, entry3);

  ollist_remove(list, entry1);

  expect_true("ollist_remove should change head to entry2", list->head == entry2);
  expect_true("ollist_remove should set length as 2", list->length == 2);
  expect_true("ollist_remove should detach entry1 from entry2", entry1->next == NULL);
  expect_true("ollist_remove should not change list items", entry2->next == entry3);
}

void test_ollist_remove_when_not_found() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(4);
  OLLEntry *entry3 = ollist_new_entry(5);
  OLLEntry *entry4 = ollist_new_entry(6);

  ollist_append(list, entry1);
  ollist_append(list, entry2);
  ollist_append(list, entry3);

  ollist_remove(list, entry4);

  expect_true("ollist_remove should not change length", list->length == 3);
  expect_true("ollist_remove should not change head", list->head == entry1);
  expect_true("ollist_remove list should not change entry1 next", entry1->next == entry2);
  expect_true("ollist_remove list should not change entry2 next", entry2->next == entry3);
  expect_true("ollist_remove list should not change entry4 next", entry4->next == NULL);
}

void test_ollist_remove_null() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(4);

  ollist_append(list, entry1);
  ollist_append(list, entry2);

  ollist_remove(list, NULL);

  expect_true("ollist_remove should not change length", list->length == 2);
  expect_true("ollist_remove should not change head", list->head == entry1);
  expect_true("ollist_remove list should not change entry1 next", entry1->next == entry2);
}

void test_ollist_shift_if_empty() {
  OLList *list = ollist_new_list();

  ollist_shift(list);

  expect_true("ollist_shift should not change length", list->length == 0);
}

void test_ollist_shift_list() {
  OLList *list = ollist_new_list();

  OLLEntry *entry1 = ollist_new_entry(3);
  OLLEntry *entry2 = ollist_new_entry(4);
  OLLEntry *entry3 = ollist_new_entry(5);

  ollist_append(list, entry1);
  ollist_append(list, entry2);
  ollist_append(list, entry3);

  ollist_shift(list);

  expect_true("ollist_remove should change head to entry2", list->head == entry2);
  expect_true("ollist_remove should set length as 2", list->length == 2);
  expect_true("ollist_remove should detach entry1 from entry2", entry1->next == NULL);
  expect_true("ollist_remove should not change list items", entry2->next == entry3);
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
  test_ollist_search_empty_list();
  test_ollist_search_not_found();
  test_ollist_search_with_one_item();
  test_ollist_search_with_several_items();
  test_ollist_remove_from_empty_list();
  test_ollist_remove_from_list_with_single_item();
  test_ollist_remove_from_end();
  test_ollist_remove_from_middle();
  test_ollist_remove_from_beginning();
  test_ollist_remove_when_not_found();
  test_ollist_remove_null();
  test_ollist_shift_if_empty();
  test_ollist_shift_list();

  return tests_result_code();
}
