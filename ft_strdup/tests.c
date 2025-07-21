#include "reference.c"
#include <stdio.h>

enum {
  very_long_string_test,
};

char *tests[] = {
  [very_long_string_test] = 0,
  "",
  "a",
  "hello",
};

function_t *functions[] = { reference, ft_strdup };

int main(){
  {
    enum { size = 100000 };
    char *s = malloc(size + 1);
    for (size_t i = 0; i < size; i++) s[i] = 'a';
    s[size] = 0;
    tests[very_long_string_test] = s;
  }

  for (size_t fn = 0; fn < sizeof(functions) / sizeof(*functions); fn++)
  for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
    char *test = tests[i];
    char *result = functions[fn](test);
    if (strcmp(test, result) != 0) {
      printf("Expected: %s\n", test);
      printf("Got: %s\n", result);
      return 1;
    }
    free(result);
  }
  printf("All tests have passed.\n");
}
