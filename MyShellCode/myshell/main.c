#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "shell.h"

int main() {

    char line[MAX_LINE];

    while(1) {

        char cwd[PATH_MAX];
        getcwd(cwd,sizeof(cwd));

        printf("\033[1;32m%s@myshell\033[0m:\033[1;34m%s\033[0m$ ",
               getlogin(),cwd);

        if(fgets(line,sizeof(line),stdin) == NULL)
            break;

        line[strcspn(line,"\n")] = 0;

        if(strlen(line)==0)
            continue;

        add_history(line);

        if(strchr(line,'|')) {
            handle_pipes(line);
            continue;
        }

        char *args[MAX_ARGS];
        int background = 0;

        parse_command(line,args,&background);

        if(builtin_command(args))
            continue;

        execute_command(args,background);
    }

    return 0;
}
