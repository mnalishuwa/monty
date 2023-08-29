#include "monty.h"

/**
 * pall - prints all elements of a list
 * Description: prints all node data in doubly lineked list
 *
 * @sp: pointer to head node of the list
 * @line_pointer: int, line_number
 *
 * Return: size_t, number of elements in the list
 */
void pall(stack_t **sp, unsigned int line_pointer)
{
	stack_t *current_node = NULL;

	(void)line_pointer;

	if (sp == NULL || *sp == NULL)
		return;

	current_node = *sp;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}

}
