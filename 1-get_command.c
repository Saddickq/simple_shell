#include "main.h"
/**
 * print_prompt - prompt the user
 * @prompt: prompt to print
 * Return: void
 */

void print_prompt(char *prompt)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		fflush(stdout);
	}
}

/**
 * get_command - get the input command from user
 * Return: command
 */
char *get_command(void)
{
	ssize_t read;
	size_t size = 0;
	char *buffer = NULL;

	print_prompt("#cisfun ");

	read = getline(&buffer, &size, stdin);
	if (read == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
