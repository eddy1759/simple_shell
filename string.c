#include "shell.h"

/**
 * _strlen - find the length of the string
 * @s: string
 * Return: string length
 */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
	{
		return (0);
	}
	while (*s++)
		i++;

	return (i);
}

/**
 * _strdup - duplicates the string
 * @s: string
 *
 * Return: pointer to the duplicate
 */
char *_strdup(char *s)
{
	int size, i;
	char *dest;

	if (!s)
	{
		return (NULL);
	}
	size = _strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
		*(dest + i) = *(s + i);
	*(dest + i) = '\0';

	return (dest);
}
