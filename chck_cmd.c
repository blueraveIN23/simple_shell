#include "shell.h"

/**
 * chck_cmd - checks validity of command
 * @cmd: command string
 *
 * Return: 0 if path is found but 1 otherwise
 */

int chck_cmd(char *cmd)
{
	char *path = _getpath(cmd);

	if (path == NULL)
	{
		return (1);
	}

	return (0);
}
