#include "../list.h"

typedef void ft_list_push_front_t(list_t **list, list_t *new);

ft_list_push_front_t ft_list_push_front, ft_list_push_front_c;

void ft_list_push_front_c(list_t **list, list_t *new) {
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
