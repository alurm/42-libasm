#include "reference.c"
#include <sys/types.h>
#include <stdio.h>
#include <assert.h>

#define size(x) (sizeof((x)) / sizeof(*(x)))

int main() {
  for (size_t fn = 0; fn < 2; fn++) {
    __auto_type get_list_size = fn ? ft_list_size : ft_list_size_c;
    __auto_type list_push_front = fn ? ft_list_push_front : ft_list_push_front_c;

    printf("Testing out the %s version.\n", fn ? "NASM" : "C");

    list_t *head = 0;

    assert(get_list_size(head) == 0);

    size_t data[] = {
      1,
      2,
      3,
    };

    for (size_t i = 0; i < size(data); i++) {
      void *datum = (void *)data[i];
      printf("%p\n", datum);
      list_push_front(&head, datum);
    }

    printf("\n");

    assert(get_list_size(head) == 3);

    for (list_t *list = head; list != 0; list = list->next) printf("%p\n", list->data);

    printf("\n");
  }

  printf("All tests have passed.\n");
  return 0;
}
