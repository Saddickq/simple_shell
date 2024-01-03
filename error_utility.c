#include "main.h"
/**
 * _putchar - puts a character
 * @c: character to put
 * Return: character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * int_to_arg - convert an integer to an argument
 * @number: integer to convert
 * Return: argumnt
 */
char *int_to_arg(int number)
{
	char *str;
	int count = 0;
	int tmp = number;

	while (number > 0)
	{
		number = number / 10;
		count++;
	}

	str = malloc(sizeof(char) * (count + 1));
	str[count] = '\0';
	count--;

	while (tmp > 0)
	{
		str[count] = ((tmp % 10) + 48);
		tmp = tmp / 10;
		count--;
	}
	return (str);
}

/**
 * _strcpy - copy a string to destination
 * @dest: The destination to copy to
 * @src: the source or where to copy from
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
