#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * File: builtins.c
 * Description: Implementation of built-in shell commands.
 */

/**
 * lsh_cd - Change the current working directory.
 * @args: The arguments passed to the command
 * (expected to contain the directory path).
 *
 * Return: Returns 1 on success, or an error code on failure.
 */
int lsh_cd(char **args);

/**
 * builtin_str - List of builtin commands.
 */
char *builtin_str[] = {
    "cd"
};

int (*builtin_func[])(char **) = {
    &lsh_cd
};

/**
 * lsh_num_builtins - Get the number of built-in commands.
 *
 * Return: Returns the number of built-in commands.
 */
int lsh_num_builtins(void)
{
    return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * lsh_cd - Change the current working directory.
 * @args: The arguments passed to the command
 * (expected to contain the directory path).
 *
 * Return: Returns 1 on success, or an error code on failure.
 */
int lsh_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("lsh");
            return (1);
        }
    }
    return (1);
}

/**
 * lsh_exit - Exit the shell program.
 * @args: The arguments passed to the command (unused).
 *
 * Return: Returns 0 to indicate the shell should exit.
 */
int lsh_exit(__attribute__((unused)) char **args)
{
	return (0);
}
