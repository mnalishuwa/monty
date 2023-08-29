#include "monty.h"

/**
 * read_line - read a line of text
 * Description: reads a line of text from stdout
 * using getline function. it is the responsibility of
 * the caller to free the memory allocated.
 *
 * @fp: pointer to file
 *
 * Return: a pointer to the string entered by the user
 */
char *read_line(FILE *fp)
{
	char *_lineptr = NULL;
	ssize_t nread;
	size_t len = 0;

	nread = getline(&_lineptr, &len, fp);

	if (nread == -1)
	{
		free(_lineptr);
		return (NULL);
	}
	if (_lineptr[nread - 1] == '\n')
		_lineptr[nread - 1] = '\0';

	return (_lineptr);
}

/**
 * free_null - frees and nulls a dynamically allocated string
 * Description: function takes a dynamically allocated string
 * and free's the string then sets it to null. It is the responsibility
 * of the caller to ensure argument passed is dynamically allocated
 * using malloc, realloc or calloc, otherwise will get invalid free error
 *
 * @dstr: dynamically allocated string
 *
 * Return: 0 on success, -1 on error
 */
int free_null(char *dstr)
{
	if (dstr == NULL)
		return (-1);
	free(dstr);
	dstr = NULL;
	return (0);
}
