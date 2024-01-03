#include "main.h"
/**
* _strncmp - Compares two strings
* @str1: First string parameter
* @str2: Second string parameter
* @n: Number of characters to compare
* Return: Integer
*/

int _strncmp(const char *str1, const char *str2, int n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
		return (0);

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 * getpath - get the path environment variable
 * @env: environment variables
 * Return: path variable if found
 */
char *getpath(char **env)
{
	char *path_variable = NULL;
	int i;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_variable = env[i] + 5;
			return (path_variable);
		}
	}

	return (NULL);
}
