#include "../list.h"
#include <stdlib.h>

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
