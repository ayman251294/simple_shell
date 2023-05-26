#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */

/* main.c */
int ex(char *inp, char **argum, char *va);
int cmdshell(char *, char **, int, char **, char **, int *);
void no_file(int lns, char *div, char **va);
char *li_m(size_t size);

/* functions.c */
int _sle(char *ring);
char *_su(char *ring);
char **split_line(char *ring, char *delim);
int _sc(char *origin, char *su);
char *nums(int n);

/* path_handler.c */
char *gen(char *name, char **environ);
char *gpath(char **environ, char *input);

/* memory_handler.c */
int arrfix(char **ring);

/* paraser.c */
char **parse_input(char *input);

#endif /* ifndef SHELL_H */
