#include "monty.h"

/**
 * _strstr - finds a substring within another string
 * Description: Search string haystack for substring needle
 *
 * @haystack: string to search
 * @needle: string to find in haystack
 *
 * Return: pointer to the beginning of the matching substring
 */

char *_strstr(char *haystack, char *needle)
{
	int start, i, len_s, len_n;

	if (haystack == NULL || needle == NULL)
	{
		perror("error: _strstr passed null values\n");
		return (NULL);
	}

	for (len_s = 0; haystack[len_s] != '\0'; len_s++)
		;
	for (len_n = 0; needle[len_n] != '\0'; len_n++)
		;
	if (len_n > len_s)
		return (NULL);

	for (start = 0; (start + len_n) <= len_s; start++)
	{
		for (i = 0; needle[i] != '\0'; i++)
		{
			if (needle[i] != haystack[start + i])
				break;
		}
		if (i == len_n)
			return (haystack + start);
	}

	return (NULL);
}
