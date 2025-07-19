#include "../list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef void ft_list_push_front_t(list_t **list, void *data);

ft_list_push_front_t ft_list_push_front, ft_list_push_front_c;

void ft_list_push_front_c(list_t **list, void *data) {
  list_t *new = malloc(sizeof(list_t));
  if (new == 0) {
    *list = 0;
    return;
  }
  new->data = data;
  new->next = *list;
  *list = new;
}

typedef int ft_list_size_t(list_t *list);

ft_list_size_t ft_list_size, ft_list_size_c;

int ft_list_size_c(list_t *list) {
  int size = 0;
  for (
    ;
    list != 0;
    size++,
    list = list->next
  );
  return size;
}

typedef void ft_list_sort_t(list_t **list, int (*cmp)(void *a, void *b));

ft_list_sort_t ft_list_sort, ft_list_sort_c;

void ft_list_sort_c(list_t **list, int (*cmp)(void *a, void *b)) {
  // Check that there are at least two elements.
  if (*list == 0 || (*list)->next == 0) return;

  for (
    _Bool swapped = 1;
    swapped;
  ) {
    swapped = 0;
    for (
      list_t **current = list;
      (*current)->next != 0;
      current = &(*current)->next
    )
    if (cmp((*current)->data, (*current)->next->data) > 0) {
      swapped = 1;

      // Before: current -> a -> b -> c
      // After:  current -> b -> a -> c

      list_t *a = *current;
      list_t *b = (*current)->next;
      list_t *c = (*current)->next->next;

      *current = b;
      b->next = a;
      a->next = c;
    }
  }
}

bool is_sorted(list_t *list, int (*cmp)(void *a, void *b)) {
  if (list == 0 || list->next == 0) return true;
  for (
    ;
    list->next;
    list = list->next
  )
  if (cmp(list->data, list->next->data) > 0) return false;
  return true;
}

int compare_intptrs(void *a, void *b) {
  return (intptr_t)a - (intptr_t)b;
}

typedef void ft_list_remove_if_t(
  list_t **list,
  void *data,
  int (*cmp)(void *a, void *b),
  void (*free)(void *)
);

ft_list_remove_if_t ft_list_remove_if, ft_list_remove_if_c;

// It's not obvious if free() should be used or not.
// Let's say that it should.
// TODO: add more introspection.
// TODO: add an asm implementation.
void ft_list_remove_if_c(
  list_t **list,
  void *data,
  int (*cmp)(void *, void *),
  void (*delete)(void *)
) {
  for (
    list_t **current = list;
    (*current) != 0;
  )
  if (cmp((*current)->data, data) == 0) {
    list_t *next = (*current)->next;
    delete((*current)->data);
    free(*current);
    *current = next;
  } else
  current = &(*current)->next;
}

int compare_always_equal(void *a, void *b) {
  return 0;
}

int compare_always_less(void *a, void *b) {
  return -1;
}

void delete_do_nothing(void *a) {}
