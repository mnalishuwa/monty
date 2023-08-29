#include "monty.h"

/**
 * pint - prints the data at the top of the stack
 * Description: print data on top of stack
 *
 * @sp: stack_t head
 * @line_pointer: int
 *
 * Return: void
 */
void pint(stack_t **sp, unsigned int line_pointer)
{
	if (sp == NULL || *sp == NULL)
		cant_pint(line_pointer);

	printf("%d\n", (*sp)->n);
}
