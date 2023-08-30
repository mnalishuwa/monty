#include "monty.h"

/**
 * run_monty - read .m file and execute each line in file
 * Description: run the monty program
 *
 * @sp: pointer to first node
 * @fp: file pointer
 * @line_number: int
 *
 * Return: void
 */

void run_monty(stack_t **sp, FILE *fp, unsigned int line_number)
{
	char *command = NULL, *lineptr = NULL;
	instruction_t *ops[8];
	size_t i;

	create_ops(ops);
	while ((lineptr = read_line(fp)) != NULL)
	{
		if (_strlen(lineptr) == 0 || lineptr[0] == '\0' || lineptr[0] == '\n')
		{
			free_null(lineptr); /* lineptr = NULL; */
			continue;
		}
		normalize_wspace(lineptr);
		if (_strlen(lineptr) == 0)
		{
			free_null(lineptr); /* lineptr = NULL; */
			continue;
		}
		arguments = _strtok(lineptr, " ");
		command = arguments[0];
		for (i = 0; i < 7 && ops[i] != NULL; i++)
		{
			if (strcmp(command, ops[i]->opcode) == 0)
				break;
		}
		if (ops[i] != NULL)
		{
			(ops[i]->f)(sp, line_number);
			free_args(arguments);
			line_number++;
			continue;
		}
		invalid_instruction(line_number, command);
		line_number++;
	}
	clean_ops(ops, 7);
}
