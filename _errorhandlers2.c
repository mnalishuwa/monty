#include "monty.h"
#include <stdio.h>

/**
 * cant_pop - write failed pop error msg to stderr
 * Description: writes error message to stderr for unsuccessful
 * pop
 *
 * @line_number: int line number
 *
 * Return: void
 */
void cant_pop(unsigned int line_number)
{
	char *ebuffer = NULL;
	size_t bsize = 0;

	free_args(arguments);
	bsize = snprintf(NULL, 0, "L%u: can't pop an empty stack\n", line_number);
	bsize++;
	ebuffer = malloc(sizeof(char) * bsize);
	if (ebuffer == NULL)
	{
		perror("cant_pint: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	snprintf(ebuffer, bsize, "L%u: can't pop an empty stack\n", line_number);
	write(STDERR_FILENO, ebuffer, bsize);
	free(ebuffer);
	exit(EXIT_FAILURE);
}

/**
 * cant_swap_add - prints error if opcode swap, add and stack short
 * Description: writes to stderr if stack short and opcode is swap
 * or add
 *
 * @line_number: int
 * @opcode: str, swap or add
 */
void cant_swap_add(unsigned int line_number, char *opcode)
{
	char *ebuffer = NULL;
	size_t bsize = 0;

	bsize = snprintf(NULL, 0, "L%u: can't swap, stack too short\n", line_number);
	bsize++;
	ebuffer = malloc(sizeof(char) * bsize);
	if (ebuffer == NULL)
	{
		perror("cant_swap_add: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	snprintf(ebuffer, bsize, "L%u: can't swap, stack too short\n", line_number);
	if (strcmp(opcode, "add") == 0)
		snprintf(ebuffer, bsize, "L%u: can't add, stack too short\n", line_number);
	write(STDERR_FILENO, ebuffer, bsize);
	free(ebuffer);
	exit(EXIT_FAILURE);
}

/**
 * cant_push - write error to stderr if cant push
 * Description: error if push arg not an int or
 * if push arg is missing
 *
 * @line_number: int, error line number
 *
 * Return: int
 */
int cant_push(unsigned int line_number)
{
	char *ebuffer = NULL;
	size_t bsize = 0;

	bsize = snprintf(NULL, 0, "L%u: usage: push integer", line_number);
	bsize++;
	ebuffer = malloc(sizeof(char) * bsize);
	if (ebuffer == NULL)
	{
		perror("cant_push: malloc failed");
		return (1);
	}
	snprintf(ebuffer, bsize, "L%u: usage: push integer", line_number);
	write(STDERR_FILENO, ebuffer, bsize);
	free(ebuffer);
	exit(EXIT_FAILURE);
}

/**
 * concat_withsep - concatenates 2 strings into specified destination
 * Description: concats 2 strings separated by a / to specified
 * destination, this is used to create a full filepath given
 * a directory and a command, it is a utility function used
 * to help search_path to search through PATH files for a
 * command/program
 *
 * @dest: output string
 * @s1: foldername string
 * @s2: command/program name
 * @sep: separator
 *
 * Return: void
 */
void concat_withsep(char *dest, char *s1, char *s2, char sep)
{
	size_t i, j;

	if (dest == NULL || s1 == NULL || s2 == NULL)
	{
		perror("error: create_path passed null\n");
	}

	for (i = 0; s1[i] != '\0'; i++)
		dest[i] = s1[i];
	dest[i] = sep;
	i++;
	for (j = 0; s2[j] != '\0'; j++)
		dest[i + j] = s2[j];
	dest[i + j] = '\n';
	dest[i + j + 1] = '\0';
}
