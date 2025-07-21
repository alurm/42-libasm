#ifndef LIBASM_BONUS_H
#define LIBASM_BONUS_H

void ft_list_push_front(list_t **list, void *data);
int ft_list_size(list_t *list);
void ft_list_sort(list_t **list, int (*cmp)(void *a, void *b));
void ft_list_remove_if(
  list_t **list,
  void *data,
  int (*cmp)(void *a, void *b),
  void (*free)(void *)
);

#endif
