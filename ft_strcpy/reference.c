#include <stddef.h>

typedef char *function_t(char *destination, const char *source);

function_t reference, ft_strcpy;

char *reference(char *destination, const char *source) {
  size_t index = 0;

  for (;;) {
    destination[index] = source[index];
    if (source[index] == 0) break;
    index++;
  }

  return destination;
}
