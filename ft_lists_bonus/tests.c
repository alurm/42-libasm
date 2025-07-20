#include "reference.c"
#include <sys/types.h>
#include <stdio.h>
#include <assert.h>

#define size(x) (sizeof((x)) / sizeof(*(x)))

int test_sort() {
  printf("# Testing ft_list_sort\n\n");

#pragma push_macro("sized")
#define sized(...) { size(((size_t[]){ __VA_ARGS__ })), (size_t[]){ __VA_ARGS__ } },
  struct {
    size_t size;
    size_t *data;
  } tests[] = {
    { 0 },
    sized(1, 2, 3)
    sized(3, 2, 1)
    sized(1)
    sized(9, 8)
    sized(4, 3, 2, 1)
    sized(1, 4, 3, 5, 2, 9)
  };
#pragma pop_macro("sized")

  for (size_t fn = 0; fn < 2; fn++) {
    printf("Testing the %s version.\n", fn ? "NASM" : "C");

    for (size_t i = 0; i < size(tests); i++) {
      __auto_type sort_list = fn ? ft_list_sort : ft_list_sort_c;
      __auto_type test = tests[i];
      __auto_type remove_if = fn ? ft_list_remove_if : ft_list_remove_if_c;

      list_t *head = 0;
    
      for (size_t i = 0; i < test.size; i++) {
        void *datum = (void *)test.data[i];
        ft_list_push_front(&head, datum);
      }

      (fn ? ft_list_sort : ft_list_sort_c)(&head, compare_intptrs);

      for (list_t *list = head; list != 0; list = list->next)
      printf("%p\n", list->data);

      // Check that the data is passed correctly.
      {
        size_t ones = 0;
        for (list_t *list = head; list != 0; list = list->next)
        if ((intptr_t)list->data == 1) ones++;

        remove_if(&head, (void *)1, compare_intptrs, delete_do_nothing);

        for (list_t *list = head; list != 0; list = list->next)
        assert((intptr_t)list->data != 1);

        assert(ft_list_size(head) == test.size - ones);
        test.size -= ones;
      }

      // Test removing only odd numbers.
      {
        size_t odd_numbers = 0;
        for (list_t *list = head; list != 0; list = list->next)
        if ((intptr_t)list->data % 2 == 1) odd_numbers++;
        // printf("Odd numbers: %zu.\n", odd_numbers);

        remove_if(&head, 0, compare_zero_if_odd, delete_do_nothing);

        // Check that all odd numberss have been deleted.
        for (list_t *list = head; list != 0; list = list->next)
        assert((intptr_t)list->data % 2 == 0);
        assert(ft_list_size(head) == test.size - odd_numbers);
        test.size -= odd_numbers;
      }

      remove_if(&head, 0, compare_always_equal, delete_do_nothing);
      assert(ft_list_size(head) == 0);

      if (!is_sorted(head, compare_intptrs)) return 1;

      printf("\n");
    }
  }
 
  return 0;
}

int test_push_and_size() {
  printf("# Testing ft_list_push_front and ft_list_size\n\n");
  
  for (size_t fn = 0; fn < 2; fn++) {
    __auto_type get_list_size = fn ? ft_list_size : ft_list_size_c;
    __auto_type list_push_front = fn ? ft_list_push_front : ft_list_push_front_c;

    printf("Testing the %s version.\n", fn ? "NASM" : "C");

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

  return 0;
}

int main() {
  if (test_push_and_size() != 0) return 1;
  if (test_sort() != 0) return 1;

  printf("# All tests have passed\n");
}
