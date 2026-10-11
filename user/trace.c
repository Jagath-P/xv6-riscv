#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

  if (argc < 3) {
    char *message = "wrong usage of trace command!\nTry again!!\n";
    write(2, message, strlen(message));
    exit(1);
  }
  int pid = fork();
  if (pid == 0) {
    int ret = trace(atoi(argv[1]));

    if (ret < 0) {
      printf("tracing failed!\n");
      exit(1);
    }

    ret = exec(argv[2], argv + 2);
    printf("exec returned: %d\n", ret);
    exit(1);
    printf("exec failed\n");
  } else {
    wait(0);
  }
}
