#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

void handle_redirection(char **args) {

    for(int i=0; args[i]!=NULL; i++) {

        if(strcmp(args[i],">")==0) {

            int fd = open(args[i+1],
                    O_CREAT | O_WRONLY | O_TRUNC,
                    0644);

            dup2(fd,STDOUT_FILENO);
            close(fd);

            args[i] = NULL;
        }

        if(strcmp(args[i],"<")==0) {

            int fd = open(args[i+1],O_RDONLY);

            dup2(fd,STDIN_FILENO);
            close(fd);

            args[i] = NULL;
        }
    }
}
