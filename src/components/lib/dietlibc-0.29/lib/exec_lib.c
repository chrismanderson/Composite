#include <unistd.h>
#include <paths.h>

extern char **environ;

int __exec_shell(const char *file, char *const argv[]);
int __exec_shell(const char *file, char *const argv[]) {
  int i;

  for (i = 0; argv[i]; i++);

  {
    const char *shell_argv[i + 1];
    shell_argv[0] = _PATH_BSHELL;
    shell_argv[1] = file;
    for (; i > 1; i--)
      shell_argv[i] = argv[i - 1];
    return execve(_PATH_BSHELL, (char*const*)shell_argv, environ);
  }
}

