#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"

void execute_command(char **args,int background) {

    pid_t pid = fork();

    if(pid == 0) {

        handle_redirection(args);

        if(execvp(args[0],args) == -1) {
            perror("myshell");
            exit(EXIT_FAILURE);
        }
    }
    else {

        if(!background)
            waitpid(pid,NULL,0);
        else
            printf("[background pid %d]\n",pid);
    }
}
