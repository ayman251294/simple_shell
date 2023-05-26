#include "shell.h"

/**
 * arrfix - Clears a double pointer
 * @ring: Double pointer to clean
 *
 * Return: 1
 */

int arrfix(char **ring)
{
	int a;

	for (a = 0; ring[a]; a++)
	{
		free(ring[a]);
	}
	free(ring);

	return (1);
}
