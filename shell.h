#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/* Function prototypes */
void print_prompt(void);
char **split_line(char *line);
int execute(char **args);
char *read_input();
void print_error(char *message);

#endif /* SHELL_H */
