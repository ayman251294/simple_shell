#include "shell.h"

/**
 * _sle - Counts the length of a string
 * @ring: string to count
 * Return: the ammount of chars of the string
*/

int _sle(char *ring)
{
	int a;

	for (a = 0; ring[a]; a++)
	{
	}

	return (a);
}

/**
 * _su - duplicate a givn string
 * @ring: string to duplicate
 * Return: A pointer to a duplicate of the string givn
*/

char *_su(char *ring)
{
	char *dup;
	int a;

	for (a = 0; ring[a]; a++)
	{
	}

	dup = malloc((sizeof(char) * a) + 1);
	if (!dup)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}

	for (a = 0; ring[a]; a++)
	{
		dup[a] = ring[a];
	}
	dup[a] = '\0';

	return (dup);
}

/**
 * split_line - splits a string into a 2d array based on delim
 * @ring: string to split
 * @delim: delimiter to take into account to split the string
 * Return: A double pointer of chars with the string splitted
*/

char **split_line(char *ring, char *delim)
{
	int a, b, chars, lns = 1;
	char **splitted, *token, *strdup;

	strdup = _su(ring);

	for (a = 0; strdup[a]; a++)
		if (strdup[a] == delim[0] || strdup[a] == delim[1])
			lns++;

	splitted = malloc((lns + 1) * sizeof(char *));
	if (!splitted)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}
	token = strtok(strdup, delim);
	b = 0;
	while (token)
	{
		chars = _sle(token);
		splitted[b] = malloc((chars + 1) * sizeof(char));
		if (!splitted)
		{
			write(2, "Unable to allocate memory", 25);
			for (; b != 0 ; b--)
				free(splitted[b - 1]);
			free(splitted);
			exit(1);
			}
		for (a = 0; a < chars; a++)
		{
			splitted[b][a] = token[a];
		}
		splitted[b][a] = '\0';
		b++;
		token = strtok(0, delim);
	}
	splitted[b] = NULL;
	free(strdup);
	return (splitted);
}

/**
 * _sc - Compares two arrays
 * @origin: 1st array
 * @su: 2nd array
 * Return: 1 if same, 0 if different
*/

int _sc(char *origin, char *su)
{
	int a;

	for (a = 0; origin[a] && su[a]; a++)
	{
		if (origin[a] != su[a])
			break;
	}

	if (a == _sle(origin) && a == _sle(su))
		return (1);
	else
		return (0);
}

/**
 * nums - Calculates the ammount of digits
 * @n: number to evaluate
 * Return: The ammount of digits
*/

char *nums(int n)
{
	int a = 0, b, number = n;
	char *strnumber;

	for (a = 0; n != 0; a++)
	{
		n = n / 10;
	}

	strnumber = malloc(sizeof(char) * (a + 1));

	for (b = 1; b <= a; b++)
	{
		strnumber[a - b] = (number % 10) + '0';
		number = number / 10;
	}
	strnumber[a] = '\0';
	return (strnumber);
}
