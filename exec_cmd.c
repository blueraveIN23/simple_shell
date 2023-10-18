#include "shell.h"

/**
 * exec_cmd - executes command if PATH is found
 * @av: argument vector
 * @file_name: name of shell executable
 * @count: prompt display tracker
 *
 * Return: nothing
 */

void exec_cmd(char **av, char *file_name, size_t count)
{
	unsigned int cmd_status;
	size_t n = count;

	char *path, **env = environ, *cmd = av[0];
	pid_t child;
	int status;


	cmd_status = chck_cmd(cmd);
	path = _getpath(cmd);

	if (cmd_status == 0)
	{
		child = fork();
		if (child == 0)
		{
			if (execve(path, av, env) == -1)
			{
				fprintf(stderr, "%s: %lu: %s: Execution Error", file_name, n, av[0]);
				exit(1);
			}
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		free(path);
		fprintf(stderr, "%s: %lu: %s:  not found\n", file_name, n, av[0]);
		return;
	}
}
