#include "main.h"

/**
 * compare - function that compares strings
 * @command: commands from user
 * @str: the string to compare with
 * Return: 1 if true, 0 if false
 */
int compare(char *command, char *str)
{
	int val = _strcmp(command, str);

	if (val == 0)
		return (1);
	else
		return (0);
}

/**
 * in_env_path - get the file path to a command
 * @command: the command entered by the user
 * Return: 1 if true and 0 if false
 */
char *in_env_path(char *command, char **env)
{
	char *file_path = NULL;
	char *path_env = getpath(env);
	char *path_clone = strdup(path_env);
	char *directory = strtok(path_clone, ":");

	if (command == NULL || env == NULL || path_env == NULL)
		return (NULL);

	while (directory != NULL)
	{
		size_t len1 = _strlen(directory);
		int len2 = _strlen(command);

		file_path = malloc(len1 + len2 + 2);
		if (!file_path)
		{
			free(path_clone);
			return (NULL);
		}
		_strcpy(file_path, directory);
		_strcat(file_path, "/");
		_strcat(file_path, command);

		if (access(file_path, F_OK) == 0 && access(file_path, X_OK) == 0)
		{
			free(path_clone);
			return (file_path);
		}
		free(file_path);
		directory = strtok(NULL, ":");
	}
	free(path_clone);
	return (NULL);
}
