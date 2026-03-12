#include <string.h>
#include "shell.h"

void parse_command(char *line, char **args, int *background) {

    int i = 0;

    args[i] = strtok(line," ");

    while(args[i] != NULL && i < MAX_ARGS-1) {

        i++;
        args[i] = strtok(NULL," ");
    }

    args[i] = NULL;

    if(i > 0 && strcmp(args[i-1],"&")==0) {

        *background = 1;
        args[i-1] = NULL;
    }
}
