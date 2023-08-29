#include "monty.h"

/**
 * swap - swaps top two data elements on stack
 * Description: swaps top data elements on stack
 *
 * @sp: head
 * @line_pointer: int, line pointer
 *
 * Return: void
 */
void swap(stack_t **sp, unsigned int line_pointer)
{
	stack_t *current_node = NULL;

	if (sp == NULL || (stack_len(*sp) < 2))
		cant_swap_add(line_pointer, "swap");

	current_node = *sp;
	current_node->n = current_node->n ^ (current_node->next)->n;
	(current_node->next)->n = current_node->n ^ (current_node->next)->n;
	current_node->n = current_node->n ^ (current_node->next)->n;
}

/**
 * add - add top 2 items on the stack
 * Description: pops adds first element to
 * next element, them pops the first element
 *
 * @sp: head
 * @line_pointer: int
 *
 * return: void
 */
void add(stack_t **sp, unsigned int line_pointer)
{
	stack_t *current_node = NULL;

	if (sp == NULL || (stack_len(*sp) < 2))
		cant_swap_add(line_pointer, "add");

	current_node = *sp;
	(current_node->next)->n += current_node->n;
	pop(sp, line_pointer);
}

/**
 * nop - does nothing
 * Description: does nothing
 *
 * @sp: top of stack
 * @line_pointer: int
 *
 * Return: void
 */
void nop(stack_t **sp, unsigned int line_pointer)
{
	(void)sp;
	(void)line_pointer;
}

/**
 * stack_len - gets the number of elements in a list
 * Description: returns the number of elements in a
 * doubly-linked list
 *
 * @h: pointer to head node in list
 *
 * Return: size_t, list size
 */
size_t stack_len(stack_t *h)
{
	stack_t *current_node = h;
	size_t list_size = 0;

	if (current_node == NULL)
		return (0);

	while (current_node)
	{
		list_size++;
		current_node = current_node->next;
	}

	return (list_size);
}
