#include "shell.h"

/**
 *searchpath - seek in the PATH, using the tokenizer for each directory
 *and puts the executable in the final of the PATH if it's found.
 *@cmd: Command entered by user.
 *@env: pointer to the string of the enviroment list.
 *Return: new_path, directory PATH followed by /"command" entered by the user
 */

char *searchpath(char *cmd, char **env)
{
	char *path = _strdup(_getenv("PATH", env));
	int i = 0, j = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = cmd;
	char *new_path = NULL;
	struct stat cmd_stat;

	if (path == NULL)
		path_notfound();
	new_path = malloc(sizeof(char) * 100);
	/* tokenizes and sends the tokens in path_array */
	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	/* cmd entered by the user is inserted at the end of the directories*/
	for (j = 0; path_array[j]; j++)
	{
		_strcpy(new_path, path_array[j]);
		_strcat(new_path, "/");
		_strcat(new_path, s2);
		_strcat(new_path, "\0");
		/* check if it exists */
		if (stat(new_path, &cmd_stat) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);
	/* for non-interactive mode */
	if (stat(cmd, &cmd_stat) == 0)
	return (_strdup(cmd));
	return (NULL);
}

/**
 *path_notfound - function in case there is no PATH.
 *
 */

void path_notfound(void)
{
	write(STDERR_FILENO, "PATH not found", 14);
	exit(EXIT_FAILURE);
}
