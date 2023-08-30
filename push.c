#include "monty.h"

/**
 * push - pushes a node onto stack
 * Description: adds a node to beginning of stack
 *
 * @sp: pointer to stack
 * @line_number: int, data item
 *
 * Return: void
 */
void push(stack_t **sp, unsigned int line_number)
{
	stack_t *new_node = NULL;

	normalize_wspace(arguments[1]);
	if ((_len_args(arguments) < 2) || (_isnum(arguments[1]) != 1))
	{
		cant_push(line_number);
	}

	new_node = malloc(sizeof(stack_t));
	memory_error(new_node);
	new_node->n = atoi(arguments[1]);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (sp == NULL)
	{
		sp = &new_node;
		return;
	}
	if (*sp == NULL)
	{
		*sp = new_node;
		return;
	}
	new_node->next = *sp;
	(*sp)->prev = new_node;
	*sp = new_node;
}

/**
 * _isdigit - checks if a given int c is a digit
 * Description: takes in int c and checks if c is a digit 0 through 9
 *
 * @c: int to be checker
 *
 * Return: 1 if c is a digit and 0 otherwise
 */

int _isdigit(int c)
{
	if (c > 47 && c < 58)
	{
		return (1);
	}
	return (0);
}

/**
 * _isnum - checks is str can be converted to int
 * Description: takes a char *, returns 1 if if
 * str can be converted to int
 *
 * @str: target string
 *
 * Return: int
 */
int _isnum(char *str)
{
	size_t i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (str[i] == ' ')
			continue;
		if (_isdigit(str[i]) != 1)
			return (0);
	}
	return (1);
}
