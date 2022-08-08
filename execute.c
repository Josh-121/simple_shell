#include "main.h"
int execute(char **args)
{
  int i;
  int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_exit
};

char *builtin_str[] = {
  "cd",
  "exit"
};

  if (args[0] == NULL)
  {
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++)
  {
    if (strcmp(args[0], builtin_str[i]) == 0)
    {
      return (*builtin_func[i])(args);
    }
  }

  return shell_process(args);
}