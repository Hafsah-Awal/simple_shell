#include "head.h"

/**
*  print_message - prints a message
*  @s: string to print
*  Owned by Hafsah/Victor
*  Return: 0 is success
*/

void print_message(char s)
{
	int message_len = strlen(&s);

	write(STDOUT_FILENO, &s, message_len);
}

