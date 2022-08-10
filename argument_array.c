#include "main.h"
char **arg_array(char *line)
{
    int size=64;
    char *str=NULL;
    char **args=NULL;
    int index;
    int args_index=0;
    int str_index=0;
    int len=0;

    args=malloc(sizeof(char *)*size);
    str = malloc(sizeof(char)*(size));
    if (!args || !str)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(line[len] != '\0')
    {
        len++;
    }

    for(index=0;index<len;index++)
    {
        if(line[index] != ' ')
            str[str_index]=line[index];
        else
        {
            str[str_index]='\0';
            args[args_index]=str;
            str = malloc(sizeof(char)*(size));
            args_index++;
            str_index=-1;
        }
        str_index++;
    }
    str[str_index]='\0';
    args[args_index]=str;
    args[args_index+1]=NULL;
    return args;
}