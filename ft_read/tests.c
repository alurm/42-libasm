#include "reference.c"
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
  int the_pipe[2];
  assert(pipe(the_pipe) != -1);
  assert(write(the_pipe[1], "Hello\n", 7) == 7);

  char buf[7];

  assert(ft_read(the_pipe[0], buf, 7) == 7);
  printf("%s", buf);

  assert(ft_read(128, buf, 1) == -1);
  assert(errno == EBADF);

  assert(write(the_pipe[1], "Hello\n", 7) == 7);
  assert(ft_read(the_pipe[0], 0, 1) == -1);
  assert(errno == EFAULT);

  assert(ft_read(the_pipe[0], buf, 7) == 7);

  assert(fcntl(the_pipe[0], F_SETFL, O_NONBLOCK) != -1);
  assert(ft_read(the_pipe[0], buf, 1) == -1);
  assert(errno == EAGAIN);

  printf("All tests have passed.\n");
}
