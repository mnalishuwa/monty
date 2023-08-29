#include "monty.h"

/**
 * _realloc - reallocates a memory block
 * Description: reallocates a memory block previously allocated by
 * malloc, calloc or realloc using malloc and free.
 *
 * @ptr: pointer or address previously allocated
 * @old_size: positive int, number of bytes allocated to ptr
 * @new_size: positive int, number of bytes in new memory block
 *
 * Return: pointer to the newly allocated block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (!ptr)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (p)
	{
		for (i = 0; i < old_size && i < new_size; i++)
			*((unsigned char *)p + i) = *((unsigned char *)ptr + i);
	}
	if (ptr)
		free(ptr);
	ptr = p;
	return (ptr);
}
