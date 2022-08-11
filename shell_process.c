#include "main.h"
int shell_process(char **args)
{
  pid_t pid;
  int status;
  
  pid = fork();
  if (pid == 0)
  {
    if (execvp(args[0], args) == -1)
    {
      perror("./hsh");
    }
    exit(EXIT_FAILURE);
  }
  else if (pid < 0) 
  {
    perror("./hsh");
  }
  
  waitpid(pid, &status, WUNTRACED);
  return 1;
}