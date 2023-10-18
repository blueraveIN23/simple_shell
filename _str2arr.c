#include "shell.h"

/**
 * str2arr - performs tokenizationa of the main file
 * @str: string to be tokenized
 * @delim: delimeter separating each entry
 *
 * Return: pointer to array
 */

char **str2arr(char *str, char *delim)
{
	int i = 0, n;

	char **arr, **a;

	arr = malloc(_strlen(str) * sizeof(char *));
	arr[i] = _strtok(str, delim);
	if (arr[i] == NULL)
	{
		free(arr);
		return (NULL);
	}
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = _strtok(NULL, delim);
	}
	comment(arr);
	a = malloc((i + 2) * sizeof(char *));
	if (a == NULL)
	{
		free_dp(arr);
		return (NULL);
	}
	for (n = 0; n < i; n++)
	{
		a[n] = _strdup(arr[n]);
		if (a[n] == NULL)
		{
			free_dp(a);
			free_dp(arr);
			return (NULL);
		}
	}
	a[i] = NULL;
	free_dp(arr);
	return (a);
}
