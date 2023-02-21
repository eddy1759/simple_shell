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
	char *lineptr = NULL;
	ssize_t nchars;
	char *tokens;
	char *lineptr_copy = NULL;
	int i;
	int num_token = 0;
	const char *delim = " \n";

	(void)ac;



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
	lineptr_copy = malloc(sizeof(char) * nchars);
       if (lineptr_copy == NULL)
       {
	       perror("Error");
	       return(-1);
       }
       strcpy(lineptr_copy, lineptr);
       tokens = strtok(lineptr, delim);

       while (tokens != NULL)
       {
	       num_token++;
	       tokens = strtok(NULL, delim);
       }
       num_token++;
       av = malloc(sizeof(char) * strlen(tokens));
       tokens = strtok(lineptr_copy, delim);

       for (i = 0; tokens != NULL; i++)
       {
	       av[i] = malloc(sizeof(char) * strlen(tokens));
	       strcpy(av[i], tokens);
	       tokens = strtok(NULL, delim);
       }
       av[i] = NULL;
       execute_command(av);
	}
	/*free up allocated memory*/
	free(lineptr);
	free(lineptr_copy);
	return (0);
}
