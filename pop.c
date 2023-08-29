#include "monty.h"

/**
 * pop - deletes a node at index
 * Description: deletes node at index from a
 * doubly-linked list. Index is set to 0 for top
 * of stack.
 *
 * @sp: pointer to first node in linked list
 * @line_pointer: current line of command
 *
 * Return: void
 */
void pop(stack_t **sp, unsigned int line_pointer)
{
	stack_t *current_node = NULL;
	unsigned int position = 0, index = 0;

	if (sp == NULL || *sp == NULL)
		cant_pop(line_pointer);

	current_node = *sp;

	while (current_node && position < index)
	{
		position++;
		current_node = current_node->next;
	}

	if (current_node == NULL && position < index)
		return; /* (-1); */

	if (index == 0)
	{
		*sp = current_node->next;
		if (current_node->next)
			(current_node->next)->prev = NULL;
		free(current_node);
		return; /* (1); */
	}
	if (current_node->prev)
		(current_node->prev)->next = current_node->next;
	if (current_node->next)
		(current_node->next)->prev = current_node->prev;
	free(current_node);
	current_node = NULL;
}
