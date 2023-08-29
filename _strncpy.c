#include "monty.h"

/**
 * _strncpy - copies a string
 * Description: receives source and destination pointers to strings and
 * copies the contents into the destinations.
 *
 * @dest: destination string or char pointer
 * @src: source string pointer
 * @n: int, number of bytes to write
 *
 * Return: A pointer to the destination string
 */

char *_strncpy(char *dest, char *src, size_t n)
{
	size_t src_index;

/* copy src contents to dest upto n bytes */
	for (src_index = 0; src_index < n && *(src + src_index) != '\0'; src_index++)
		*(dest + src_index) = *(src + src_index);
/* Pad the rest of the string with NULL bytes */
	for (; src_index < n; src_index++)
		*(dest + src_index) = '\0';

	return (dest);
}
