#include "shell.h"

/**
 * main - entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	char *line;
	char **args;
	int status;
	size_t bufsize = 0;

	do {
		print_prompt();
		line = NULL;

		getline(&line, &bufsize, stdin);
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);

	} while (status);

	return (EXIT_SUCCESS);
}
