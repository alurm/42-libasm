#include "reference.c"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum {
  very_long_string_test
};

struct test {
  char *destination;
  char *source;
} tests[] = {
  [very_long_string_test] = { 0 },
  { (char[100]){ 0 }, "Hello" },
  { (char[100]){ 0 }, "" },
  { (char[100]){ "wrong" }, "correct" },
};

function_t *functions[] = { reference, ft_strcpy };

int main() {
  {
    enum { size = 100000 };
    char *s = malloc(size + 1);
    char *d = malloc(size + 1);
    for (size_t i = 0; i < size; i++)
    s[i] = 'a';
    s[size] = 0;
    __auto_type t = &tests[very_long_string_test];
    t->source = s;
    t->destination = d;
  }

  for (size_t fn = 0; fn < 2; fn++) {
    printf("Testing the %s function.\n", fn == 0 ? "reference" : "assembly");
    for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
      struct test test = tests[i];
      char *result = functions[fn](test.destination, test.source);
      if (result != test.destination) {
        printf("Expected the result to match the destination\n");
        return 1;
      }
      if (strcmp(test.destination, test.source) != 0) {
        printf("Expected the destination to match the source\n");
        printf("Source: %s\n", test.source);
        printf("Destination: %s\n", test.destination);
        return 1;
      }
    }
  }
  printf("All tests have passed.\n");
  return 0;
}
