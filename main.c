#include "monty.h"

int free_null(char *dstr);
char **arguments;

/**
 * main - monty program entry point
 * Description: begin program
 *
 * @argc: int argument count
 * @argv: char ** array of string args
 *
 * Return: int 0 success
 */
int main(int argc, char **argv)
{
	stack_t *sp = NULL;
	FILE *bytecode_fp;
	char *command = NULL, *lineptr = NULL;
	unsigned int i, lnumber;
	instruction_t *ops[8];

	_noargs(argc);
	bytecode_fp = fopen(argv[1], "r");
	/* file_openerror(file_name, bytecode_fp); */
	create_ops(ops);
	while ((lineptr = read_line(bytecode_fp)) != NULL)
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
		{ /* handle SIGSEV when push is called noargs */
			(ops[i]->f)(&sp, lnumber);
			free_args(arguments);
			lnumber++;
			continue;
		}
		invalid_instruction(lnumber, command);
	}
	clean_ops(ops, 7);
	free_stack(sp);
	fclose(bytecode_fp);
	return (0);
}

/**
 * create_ops - takes an array of instruction_t and fills with instructions
 * Description: fills an array with instruction_t structures
 *
 * @ops: array of instruction_t
 *
 * Return: void
 */
void create_ops(instruction_t **ops)
{
	void (*fs[])(stack_t **sp, unsigned int lp) = {add, nop, pall, pint, pop,
						       push, swap, NULL};
	char *opcodes[] = {"add", "nop", "pall", "pint", "pop", "push", "swap", NULL};
	size_t i;

	for (i = 0; opcodes[i] != NULL; i++)
	{
		ops[i] = malloc(sizeof(instruction_t));
		ops[i]->opcode = opcodes[i];
		ops[i]->f  = fs[i];
	}
}

/**
 * clean_ops - free up instruction_t ops array
 * Description: free up memory malloced by
 * create_ops function
 *
 * @ops: instruction_t array
 * @size_ops: int, number of instructions
 *
 * Return: void
 */
void clean_ops(instruction_t *ops[], size_t size_ops)
{
	size_t i;

	for (i = 0; i < size_ops && ops[i] != NULL; i++)
		free(ops[i]);
}

/**
 * free_stack - frees linked list
 * Description: takes apointer to first node
 * in doubly-linked list and frees the list
 *
 * @head: pointer to first node in list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current_node = head;

	if (head == NULL)
		return;

	while (current_node)
	{
		current_node = current_node->next;
		free(head);
		head = current_node;
	}
}
