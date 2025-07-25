#ifndef LIBASM_BONUS_H
#define LIBASM_BONUS_H

int ft_atoi_base(const char *string, int base);

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

// I prefer this way.
typedef t_list list_t;

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
