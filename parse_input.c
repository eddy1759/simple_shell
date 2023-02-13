#include "shell.h"

/**
 * parse_input - parses the line entered by the user
 * @line: the given input
 *
 * Return: an array of tokens present in @line
 */
char **parse_input(char *line)
{
	char **tokens;
	char *toks, *temp;
	int i;

	if (!line)
	{
		return (0);
	}
	tokens = malloc(sizeof(char *) * _strlen(line));

	if (!tokens)
	{
		perror("NO memory allocated");
		return (NULL);
	}
	temp = _strdup(line);
	toks = strtok(temp, " ");

	for (i = 0; toks; i++)
	{
		tokens[i] = _strdup(toks);
		toks = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(temp);
	return (tokens);
}
