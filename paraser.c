#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * **parse_input - Function to parse user input into separate arguments
 * @input: arrays
 *
 * Return: tokens
 */
char **parse_input(char *input)
{
	char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
	char *token;
	int position = 0;

	if (!tokens)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[position] = NULL;

	return (tokens);
}
