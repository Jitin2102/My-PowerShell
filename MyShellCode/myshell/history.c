#include <stdio.h>
#include <string.h>
#include "shell.h"

char history[MAX_HISTORY][MAX_LINE];
int history_count = 0;

void add_history(char *cmd) {

    if(history_count < MAX_HISTORY) {
        strcpy(history[history_count],cmd);
        history_count++;
    }
}

void show_history() {

    for(int i=0;i<history_count;i++)
        printf("%d %s\n",i+1,history[i]);
}
