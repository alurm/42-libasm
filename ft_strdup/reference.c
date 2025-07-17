#include <stdlib.h>
#include <string.h>

typedef char *function_t(const char *s);

function_t reference, ft_strdup;

char *reference(const char *s) {
  size_t len = strlen(s);
  char *result = malloc(len + 1);
  if (result == 0) return 0;

  strcpy(result, s);
  result[len] = 0;

  return result;
}
