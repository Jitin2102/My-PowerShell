#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

int builtin_command(char **args) {

    if(args[0] == NULL)
        return 1;

    if(strcmp(args[0],"exit")==0)
        exit(0);

    if(strcmp(args[0],"cd")==0) {

        if(args[1] == NULL)
            printf("cd: missing argument\n");
        else
            chdir(args[1]);

        return 1;
    }

    if(strcmp(args[0],"history")==0) {
        show_history();
        return 1;
    }

    if(strcmp(args[0],"clear")==0) {
        system("clear");
        return 1;
    }

    return 0;
}
