#include "main.h"
/**
 * parse_input - chech and remove delimeters
 * @buffer: the string to be parsed
 * Return: an array of pointers
 */

char **parse_input(char *buffer)
{
	char *token;
	char **argv = NULL;
	int index = 0, counter = 0;
	char *copy1, *copy = _strdup(buffer);

	token = strtok(copy, DELIM);
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, DELIM);
	}
	free(copy);
	argv = malloc(sizeof(char *) * (counter + 1));
	if (argv == NULL)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	copy1 = _strdup(buffer);
	token = strtok(copy1, DELIM);
	while (token != NULL)
	{

		argv[index++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	free(copy1);

	argv[index] = NULL;
	free(buffer);
	return (argv);
}
/**
 * free_argv - free memory for argv
 * @argv: memory block to free
 */
void free_argv(char **argv)
{
	int index;

	if (argv == NULL)
		return;
	for (index = 0; argv[index] != NULL; index++)
		free(argv[index]);
	free(argv);
}
