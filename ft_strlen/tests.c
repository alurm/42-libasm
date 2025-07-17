#include "reference.c"

#include <stdio.h>

struct test {
  char *input;
} tests[] = {
  { "", },
  { "Hello!", },
  { "\0Garbage" },
  { "\n" },
};

int main() {
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
