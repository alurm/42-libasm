#include <stddef.h>

typedef int function_t(const char *s1, const char *s2);

function_t reference, ft_strcmp;

int reference(const char *s1, const char *s2) {
  size_t index = 0;
  for (;;) {
    int diff = (unsigned char)s1[index] - (unsigned char)s2[index];
    if (diff != 0) return diff;
    if (s1[index] == 0 && s2[index] == 0) return 0;
    index++;
  }
}
