#include "monty.h"

/**
 * _strlen - computes the length of a string
 * Description: take a string pointer n and returns the length of the string
 *
 * @s: string input for which to determine length
 *
 * Return: int, the length of the string
 */

int _strlen(char *s)
{
	int len_s;

	if (s == NULL)
	{
		return (-1);
	}

	for (len_s = 0; *(s + len_s) != '\0'; len_s++)
		;
	return (len_s);
}
