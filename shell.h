#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

char **parse_input(char *line);
int _strlen(const char *s);
char *_strdup(char *s);

#endif
