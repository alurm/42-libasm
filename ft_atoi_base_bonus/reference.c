#include <sys/types.h>
#include <assert.h>

typedef int function_t(const char *string, int base);

function_t reference, ft_atoi_base;
int ft_atoi_base_value_of_digit(char);

/// Computes the numeric value of a digit.
/// 16 is returned for invalid digits, since it's invalid in any base.
static int value_of_digit(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  return 16;
}

int reference(const char *string, int base) {
  int result = 0;
  size_t index = 0;

  if (base < 2 || base > 16) return 0;

  if (*string == '-') index++;

  for (;;) {
    char digit = string[index];
    int value = value_of_digit(digit);
    {
      int value_2 = ft_atoi_base_value_of_digit(digit);
      assert(value == value_2);
    }

    if (value >= base) break;

    result *= base;
    result += value;

    // atoi on school's computers doesn't check for overflow.
    // if (__builtin_mul_overflow(result, base, &result)) return 0;
    // if (__builtin_add_overflow(result, value, &result)) return 0;

    index++;
  }

  if (*string == '-') result *= -1;

  return result;
}
