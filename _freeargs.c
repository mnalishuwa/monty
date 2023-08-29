#include "monty.h"

/**
 * free_args - frees a dynamically allocated array of strings
 * Description: frees an array of strings
 *
 * @args: string array to be freed
 *
 * Return: void
 */
void free_args(char **args)
{
	size_t i;

	if (args == NULL)
	{
		/* perror("error - free_args, args is null"); */
		return;
	}

	for (i = 0; args[i] != NULL; i++)
	{
		if (args != NULL)
			free(args[i]);
		args[i] = NULL;
	}
	free(args);
	args = NULL;
}


/**
 * _len_args - gets the number of arguments
 * Description: receives an array of string and returns the number of arguments
 *
 * @args: string array
 *
 * Return: int, number of arguments
 */
int _len_args(char **args)
{
	size_t arglen;


	if (args == NULL)
		return (-1);

	for (arglen = 0; args[arglen] != NULL; arglen++)
		;

	return (arglen);
}
