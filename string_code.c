#include "head.h"

/**
 * string_compare - Compares two strings.
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 * Return: Difference between the strings.
*/

int string_compare(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	output = (*(s1 + i) - *(s2 + i));

	return (output);
}

/**
 * string_length - Returns the length of a string.
 * @s: The string to find the length of.
 * Return: The length of the string.
 */

int string_length(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * string_compare_2 - compares two strings up to n bytes
 * @s1: compared to s2
 * @s2: compared to s1
 * @n: number of bytes
 *
 * Return: difference between s1 and s2
 */
int string_compare_2(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * duplicate_string - creates a duplicate of a given string
 * @s: string to be duplicated
 * Return: pointer to the duplicate string
*/
char *duplicate_string(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = string_length(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
 * find_char - Finds the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to locate.
 * Return: A pointer to the first occurrence of @c in @s,
 * or NULL if the character is not found.
 */

char *find_char(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

