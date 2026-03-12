#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

void handle_pipes(char *line) {

    char *cmd1 = strtok(line,"|");
    char *cmd2 = strtok(NULL,"|");

    if(cmd2 == NULL)
        return;

    int fd[2];
    pipe(fd);

    if(fork()==0) {

        dup2(fd[1],STDOUT_FILENO);
        close(fd[0]);

        char *args[MAX_ARGS];
        int bg=0;

        parse_command(cmd1,args,&bg);

        execvp(args[0],args);
    }

    if(fork()==0) {

        dup2(fd[0],STDIN_FILENO);
        close(fd[1]);

        char *args[MAX_ARGS];
        int bg=0;

        parse_command(cmd2,args,&bg);

        execvp(args[0],args);
    }

    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);
}
