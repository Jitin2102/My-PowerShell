#ifndef SHELL_H
#define SHELL_H

#define MAX_LINE 1024
#define MAX_ARGS 100
#define MAX_HISTORY 100

void parse_command(char *line, char **args, int *background);
void execute_command(char **args, int background);
int builtin_command(char **args);

void handle_pipes(char *line);
void handle_redirection(char **args);

void add_history(char *cmd);
void show_history();

#endif
