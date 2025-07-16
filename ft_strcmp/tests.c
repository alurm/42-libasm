#include "reference.c"

#include <stdio.h>
#include <string.h>

struct test {
  char *s1;
  char *s2;
} tests[] = {
  { "", "" },
  { "a", "b" },
  { "b", "a" },
  { "", "diff" },
  { "adiff", "a" },
  { "\xf0", "\xf1" },
  { (char[]){ 254, 0 }, (char[]){ 253, 0 } },
  { (char[]){ 254, 0 }, (char[]){ 255, 0 } },
  { (char[]){ 255, 0 }, (char[]){ 255, 0 } },
  { (char[]){ 255, 0 }, (char[]){ 0 } },
};

int main(void) {
  for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
    struct test test = tests[i];
    printf("s1: %s.\n", test.s1);
    printf("s2: %s.\n", test.s2);
    int libc = strcmp(test.s1, test.s2);
    int ref = reference(test.s1, test.s2);
    int nasm = ft_strcmp(test.s1, test.s2);
    printf("libc: %d.\n", libc);
    printf("reference: %d.\n", ref);
    printf("nasm: %d.\n", nasm);
    printf("\n");

    if (nasm != libc) {
      printf("NASM's and libc's behaviour differs\n.");
      return 1;
    }
  }
  printf("All tests have passed.\n");
}
