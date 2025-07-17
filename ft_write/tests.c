#include "reference.c"
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>

enum {
  pipe_test
};

struct test {
  int fd;
  const void *buf;
  size_t count;
  ssize_t result;
  int the_errno;
} tests[] = {
  [pipe_test] = { -1, "Hello", 5, -1, EPIPE },
  { 1, "Hello\n", 6, 6 },
  { 1, "", 0, 0 },
  { 128, "", 0, -1, EBADF },
  { 1, 0, 10, -1, EFAULT },
};

int main() {
  int the_pipe[2];
  assert(pipe(the_pipe) != -1);
  assert(close(the_pipe[0]) != -1);
  assert(signal(SIGPIPE, SIG_IGN) != SIG_ERR);
  tests[pipe_test].fd = the_pipe[1];

  for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
    struct test t = tests[i];
    printf("# A write.\n");
    ssize_t result = ft_write(t.fd, t.buf, t.count);
    int the_errno = errno;
    if (result != t.result) {
      printf("Expected result to be: %zd\n", t.result);
      printf("Got: %zd\n", result);
      return 1;
    }
    if (result == -1 && (the_errno != t.the_errno)) {
      printf("Expected errno to be: %d\n", t.the_errno);
      printf("Got: %d\n", the_errno);
      return 1;
    }
    if (result == -1) perror("Write: errno");
  }
  printf("All tests have passed.\n");
}
