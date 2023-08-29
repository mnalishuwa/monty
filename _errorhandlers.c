#include "monty.h"

/**
 * _noargs - checks if the program has receive correct number of args
 * Description: checks that the program receives args from the
 * commandline, prints an error if no args are received
 *
 * @number_ofargs: int, argc received from main
 *
 * Return: int, number of bytes written to stderr_file no
 */
int _noargs(int number_ofargs)
{
	char *error_buffer = "USAGE: monty file\n";
	size_t buffer_size = strlen(error_buffer);

	if ((number_ofargs - 1) <= 0)
	{
		write(STDERR_FILENO, error_buffer, buffer_size);
		exit(EXIT_FAILURE);
	}
	return (0);
}


/**
 * file_openerror - checks if an error occured when opening file
 * Description: checks if an error occured when opening file
 * writes error message to stderr_file number
 *
 * @file_pointer: pointer to file stream
 * @filename: str file name
 *
 * Return: int
 */
int file_openerror(char *filename, FILE *file_pointer)
{
	char *error_buffer = NULL;
	char *error_message = "Error: Can't open file";
	size_t buffer_size = 0;

	if (file_pointer == NULL)
	{
		buffer_size = strlen(error_message) + strlen(filename) + 3;
		error_buffer = malloc(sizeof(char) * buffer_size);
		concat_withsep(error_buffer, error_message, filename, ' ');
		write(STDERR_FILENO, error_buffer, buffer_size);
		free(error_buffer);
		free_args(arguments);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * memory_error - exits on malloc failure
 * Description: writes error to stderr if malloc unsuccessful
 *
 * @node: stack_t pointer to stack node
 *
 */
void memory_error(stack_t *node)
{
	char *error_buffer = "Error: malloc failed\n";
	size_t buffer_size = strlen(error_buffer);

	if (node == NULL)
	{
		write(STDERR_FILENO, error_buffer, buffer_size);
		free_args(arguments);
		exit(EXIT_FAILURE);
	}
}

/**
 * invalid_instruction - print an error if a line has an invalid opcode
 * Description: writes an error to stderr if opcode is invalid
 *
 * @line_number: int, line number
 * @opcd: string, opcode
 *
 * Return: int, 0 success
 */
int invalid_instruction(unsigned int line_number, char *opcd)
{
	char *ebuffer = NULL;
	size_t bsize = 0;

	bsize = snprintf(NULL, 0, "L%u: unknown instruction %s\n", line_number, opcd);

	ebuffer = malloc(sizeof(char) * bsize + 1);
	if (ebuffer == NULL)
	{
		perror("invalid instruction: malloc failed");
		return (-1);
	}
	bsize++;
	snprintf(ebuffer, bsize, "L%u: unknown instruction %s\n", line_number, opcd);
	write(STDERR_FILENO, ebuffer, bsize);
	free(ebuffer);
	free_args(arguments);
	exit(EXIT_FAILURE);
}

/**
 * cant_pint - write failed pint error msg to stderr
 * Description: writes error message to stderr for unsuccessful
 * pint
 *
 * @line_number: line number
 *
 * Return: void
 */
void cant_pint(unsigned int line_number)
{
	char *ebuffer = NULL;
	size_t bsize = 0;

	free_args(arguments);
	bsize = snprintf(NULL, 0, "L%u: can't pint, stack empty\n", line_number);
	bsize++;
	ebuffer = malloc(sizeof(char) * bsize);
	if (ebuffer == NULL)
	{
		perror("cant_pint: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	snprintf(ebuffer, bsize, "L%u: can't pint, stack empty\n", line_number);
	write(STDERR_FILENO, ebuffer, bsize);
	free(ebuffer);
	exit(EXIT_FAILURE);
}
