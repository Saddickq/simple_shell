#include "main.h"
/**
 * err_mess - print error messages
 * @execution_count: the number of times the program runs
 * @argv: the commands entered by the user
 * @program_name: the name of the program
 * Return: void
 */
void err_mess(int execution_count, char **argv, char *program_name)
{
	char err_msg[200];
	char *str = int_to_arg(execution_count);

	memset(err_msg, '\0', sizeof(err_msg));
	_strcpy(err_msg, program_name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, str);
	_strcat(err_msg, ": ");
	_strcat(err_msg, argv[0]);
	_strcat(err_msg, ": not found\n");
	write(STDERR_FILENO, err_msg, _strlen(err_msg));
	free(str);
}
/**
 * print_env_var - environment variables
 * @env: variables
 * Return: void
 */
void *print_env_var(char **env)
{
	int i = 0;

	if (env == NULL)
		return (NULL);

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (NULL);
}

