#include "shell.h"

/**
 * main - prints a string
 * @ac: argument count
 * @av: argument vector to the function
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *prompt = "$ ";
	size_t n = 0;
	char *lineptr;
	ssize_t nchars;
	char **tokens;

	(void)ac;
	(void)av;

/*create an infinite loop*/
	while (1)
	{
	printf("%s", prompt);
	nchars = getline(&lineptr, &n, stdin);

	/*check if the getline function failed or reached EOF or user CTRL + D*/

	if (nchars == -1)
	{
		printf("Exiting shell..\n");
		return (-1);
	}
	tokens = parse_input(lineptr);

	if (!tokens || !tokens[0])
	{
		continue;
	}
	printf("%s", lineptr);
	}
	/*free up allocated memory*/
	free(lineptr);
	return (0);

}
