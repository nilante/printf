#include "main.h"
/**
* _puts _ prints a string with newline
* @str: the string to print
* return: void
*/
int _puts(char *str)
{
	char *a = str;
	while (*str)
		_putchar(*str++);
	return (str - a);
}
/**
* _putchar - writes the character c to std out
* @c: the character to print
* return: on success 1
* on error, -1 is returned, and error is set appropreately
*/
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];
	if (c == BUF_FLUSH || i >= OUTPUT_BUT_SIZE)
{
	write(1, buf, i);
	i = 0;
}
if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}
