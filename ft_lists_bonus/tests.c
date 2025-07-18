#include "reference.c"
#include <sys/types.h>
#include <stdio.h>
#include <assert.h>

#define size(x) (sizeof((x)) / sizeof(*(x)))

int main() {
  for (size_t fn = 0; fn < 2; fn++) {
    __auto_type get_list_size = fn ? ft_list_size : ft_list_size_c;
    __auto_type list_push_front = fn ? ft_list_push_front : ft_list_push_front_c;

    list_t *head = 0;

    list_t nodes[] = {
      { (void *)1 },
      { (void *)2 },
      { (void *)3 },
    };

    for (size_t i = 0; i < size(nodes); i++) {
      list_t *node = &nodes[i];
      printf("%p\n", node->data);
      list_push_front(&head, &nodes[i]);
    }

    printf("\n");

    assert(get_list_size(head) == 3);

    for (list_t *list = head; list != 0; list = list->next) printf("%p\n", list->data);

    printf("\n");

  }

  printf("All tests have passed.\n");
  return 0;
}
