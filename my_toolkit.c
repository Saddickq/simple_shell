#include "main.h"

/**
 * _strdup - duplicates the input string to differnt block in the memory
 * @input: string to duplicate
 * Return: a pointer to the duplicated string
 */
char *_strdup(char *input)
{
	size_t len = 0;
	char *copy = NULL;

	if (input == NULL)
		return (NULL);

	while (input[len] != '\0')
		len++;

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	_strcpy(copy, input);
	return (copy);
}

/**
 * _strlen - determine the length of a string
 * @input: the string to be examined
 * Return: length of the string
 */
int _strlen(char *input)
{
	int len = 0;

	while (input[len] != '\0')
		len++;

	return (len);
}
/**
 * _strcat - add two strings together
 * @dest: the string to be added to
 * @src: the string to add
 * Return: destination string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings lexigraphically
 * @str1: string to compare
 * @str2: string to compare
 * Return: 0 if they are thesame and the difference if the are not thesame
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	else if (str1[i] == '\0')
		return (-1);
	else
		return (1);
}
