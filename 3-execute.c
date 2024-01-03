#include "main.h"
/**
 * execusioner - a function that executes a command passed by the user
 * @argv: the command entered by the user
 * @pro_name: name of programme
 * @execution_count: the number of times a programme runs
 * @exit_code: exit codes
 * Return: void
 */

void execusioner(char **argv, char *pro_name, int execution_count,
		int *exit_code)
{
	pid_t pid;
	int exe, status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed....\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		exe = execve(argv[0], argv, NULL);
		if (exe == -1)
		{
			err_mess(execution_count, &argv[0], pro_name);
			free_argv(argv);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		if (!WIFEXITED(status))
		{
			*exit_code = 127;
		}
		else
		{
			*exit_code = WEXITSTATUS(status);
		}
	}
}
