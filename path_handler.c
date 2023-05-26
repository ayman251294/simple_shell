#include "shell.h"

/**
 * gen - gets the env variable needed
 * @name: name of the env variable
 * @environ: env variables
 * Return: the line with the env variable
*/

char *gen(char *name, char **environ)
{
	int a, b, k;

	k = _sle(name);
	for (a = 0; environ[a]; a++)
	{
		for (b = 0; environ[a][b] == name[b]; b++)
		{
		}
		if (b == k && environ[a][b] == '=')
			return (environ[a]);

	}
	return (NULL);
}

/**
 * gpath - Gets the PATH variable
 * @environ: enviroment variable
 * @input: inp pass by user
 * Return: the splitted PATH variable
*/

char *gpath(char **environ, char *input)
{
	char **path = NULL, *inp;
	unsigned int input_len, path_len, a, b, k;
	struct stat st;

	path = split_line(gen("PATH", environ), "=:");
	input_len = _sle(input);

	for (a = 1; path[a]; a++)
	{
		path_len = _sle(path[a]);
		inp = malloc(sizeof(char) * (path_len + input_len + 2));
		if (!inp)
		{
			write(2, "Unable to allocate memory", 25);
			exit(1);
		}

		for (b = 0; path[a][b]; b++)
			inp[b] = path[a][b];

		inp[b++] = '/';

		for (k = 0; input[k]; k++)
			inp[b + k] = input[k];

		inp[b + k] = '\0';

		if (stat(inp, &st) == 0)
		{
			arrfix(path);
			return (inp);
		}
		free(inp);
	}
	arrfix(path);

	return (NULL);
}
