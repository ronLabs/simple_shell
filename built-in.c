#include "shell.h"

/**
 *_printenv - print the env if the user type "env".
 *@environ: pointer char to the string of the enviroment list.
 *Return: 0
 */

int _printenv(char **environ)
{
	int i = 0, length = 0;

	/* prints the env followed by new line */
	while (environ[i] != NULL)
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 *_getenv - get the env if a user type other command (no "exit", no "env")
 *@name: pointer to the name of the environment variable
 *@env: pointer char to the string of the enviroment list.
 *Return: The direction of the directories of env variable or "Not found".
 */

char *_getenv(const char *name, char **env)
{
	int i = 0;
	int j = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	/* search in the env */
	while (env[i] != NULL)
	{
		/* if the name is found */
		while (env[i][j] == name[j])
			j++;
		/* and if this have "=" will return what follows after */
		if (env[i][j] == '=')
		{
			j++;
			return (&(env[i][j]));
		}
		i++;
		j = 0;
	}
	/* If not found */
	/*write(STDOUT_FILENO, "Not found", 9);*/
	return (NULL);
}
