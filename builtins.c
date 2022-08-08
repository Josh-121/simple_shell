#include "main.h"
int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_exit
};

char *builtin_str[] = {
  "cd",
  "exit"
};

int lsh_num_builtins()
{
  return sizeof(builtin_str) / sizeof(char *);
}

int lsh_cd(char **args)
{
  if (args[1] == NULL)
  {
    fprintf(stderr, "./hsh: expected argument to \"cd\"\n");
  }
  else
  {
    if (chdir(args[1]) != 0)
    {
      perror("./hsh");
    }
  }
  return 1;
}

int lsh_exit()
{
  return 0;
}