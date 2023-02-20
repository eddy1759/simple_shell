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
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 * 
 * Return: 0 if equal, -ve if @s1 < @s2, else +ve
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strstr - implementation of the strstr function
 * @haystack: string to search
 * @needle: the substring to find
 * 
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);

	return (NULL);
}

/**
 * _strcpy - copies the content of a string to another
 * @dest: the destination string
 * @src: the source of the contents to be copied
 * 
 * Return: @dest
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strcat - concatenate two strings
 * @dest: the destination string
 * @src: the source string
 * 
 * Return: the result of concatenation
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}