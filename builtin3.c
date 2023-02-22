#include "shell.h"

/**
 * _mycd - changes the current directory of the process
 * @info: Structured containing potential arguments.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
char buffer[1024], *dir = NULL;
int chdir_ret = -1;

if (info->argv[1] == NULL)
{
dir = _getenv(info, "HOME=");
}
else if (_strcmp(info->argv[1], "-") == 0)
{
dir = _getenv(info, "OLDPWD=");
if (dir == NULL)
{
_puts(getcwd(buffer, 1024)), _putchar('\n');
return (1);
}
_puts(dir), _putchar('\n');
}
else
{
dir = info->argv[1];
}
if (dir == NULL)
{
chdir_ret = chdir((dir = _getenv(info, "PWD")) ? dir : "/");
}
else
{
chdir_ret = chdir(dir);
}
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(dir), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}



