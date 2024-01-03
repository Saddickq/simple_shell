#include "main.h"
/**
 * main - shell program
 * @argc: unused argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	int execution_count = 1, exit_code = 0;
	char **res = NULL, *input = NULL, *file_path = NULL;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		input = get_command();
		res = parse_input(input);
		if (res != NULL && res[0] != NULL)
		{
			if (compare(res[0], "exit"))
			{
				free_argv(res);
				break;
			}
			if (compare(res[0], "env"))
			{
				print_env_var(env);
				free_argv(res);
				continue;
			}
			if (res[0][0] != '/')
			{
				file_path = in_env_path(res[0], env);
				if ((file_path) != NULL)
				{
					free(res[0]);
					res[0] = file_path;
				}
				else
				{
					exit_code = 127;
					err_mess(execution_count, res, argv[0]);
					free_argv(res);
					execution_count++;
					continue;
				}
			}
			exit_code = 0;
			execusioner(res, argv[0], execution_count, &exit_code);
		}
		free_argv(res);
		execution_count++;
	}
	return (exit_code);
}
