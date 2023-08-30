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
	stack_t *top = NULL;
	char *file_name = NULL;
	unsigned int lnumber = 1;
	FILE *bytecode_fp;

	_noargs(argc);
	file_name = argv[1];
	bytecode_fp = fopen(file_name, "r");
	file_openerror(file_name, bytecode_fp);

	run_monty(&top, bytecode_fp, lnumber);
	free_stack(top);
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
	(void)size_ops;

	for (i = 0; ops[i] != NULL; i++)
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
