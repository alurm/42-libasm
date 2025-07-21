#include "reference.c"

#include <stdio.h>
#include <stdlib.h>

enum {
  very_long_string_test,
};

struct test {
  char *input;
} tests[] = {
  [very_long_string_test] = { 0 },
  { "", },
  { "Hello!", },
  { "\0Garbage" },
  { "\n" },
};

int main() {
  {
    enum { size = 100000 };
    char *s = malloc(size + 1);
    for (size_t i = 0; i < size; i++)
    s[i] = 'a';
    s[size] = 0;
    tests[very_long_string_test].input = s;
  }

  for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
    struct test test = tests[i];
    char *input = test.input;
    size_t a = reference(input);
    size_t b = ft_strlen(input);
    if (a != b) {
      printf("Input: %s.\n", input);
      printf("Expected: %zu.\n", a);
      printf("Got: %zu.\n", b);
      return 1;
    }
  }
  printf("All tests have passed.\n");
  return 0;
}
