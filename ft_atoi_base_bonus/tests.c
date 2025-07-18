#include "reference.c"
#include <stdio.h>
#include <stdlib.h>

struct {
  char *string;
  int base;
} strtol_tests[] = {
  { "123", 8 },
  { "42", 10 },
  { "12355", 3 },
  { "af", 16 },
  { "AF", 16 },
  { "AF", 15 },
  { "af", 15 },
};

char *atoi_tests[] = {
  "",
  "123",
  "934924793284729347",
   "-3",
   "-23498723493274",
};

#define size(x) (sizeof((x)) / sizeof(*(x)))

function_t *functions[] = {
  reference,
  ft_atoi_base,
};

int main() {
  for (size_t fn = 0; fn < size(functions); fn++) {
    printf("Testing the %s version.\n", fn == 0 ? "C" : "NASM");

    for (size_t i = 0; i < size(atoi_tests); i++) {
      char *s = atoi_tests[i];
      int libc = atoi(s);
      int ref = functions[fn](s, 10);
      if (libc != ref) {
        printf("Input: %s.\n", s);
        printf("Expected: %d.\n", libc);
        printf("Got: %d.\n", ref);
        return 1;
      }
    }

    for (size_t i = 0; i < size(strtol_tests); i++) {
      __auto_type test = strtol_tests[i];
      int libc = strtol(test.string, 0, test.base);
      int ref = functions[fn](test.string, test.base);
      if (libc != ref) {
        printf("Input: { base: %d, string: %s }.\n", test.base, test.string);
        printf("Expected: %d.\n", libc);
        printf("Got: %d.\n", ref);
        return 1;
      }
    }
  }
}
