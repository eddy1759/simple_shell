#include "shell.h"

void execute_command(char **av)
{
	char *command = NULL;
	char *actual_command = NULL;

	if (av)
	{
		/*get the command*/
		command = av[0];
		/*generate the path to this command before parsing it to execve*/
		actual_command = get_location(command);

		/*execute the actual command with execve*/
		if (execve(actual_command, av, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
