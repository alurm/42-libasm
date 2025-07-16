#include <stddef.h>

typedef size_t function_t(const char *string);

function_t reference, ft_strlen;

size_t reference(const char *string) {
  size_t index = 0;
  while (string[index] != 0) index++;
  return index;
}
