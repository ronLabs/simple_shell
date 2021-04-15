#include "shell.h"
/**
 *main - Shell program.
 *@argc: unused.
 *@argv: shell argument.
 *@env: pointer to the enviroment list.
 *Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[], char **env)
{
	char *buf = NULL;
	size_t sizebuf = 0;
	ssize_t userInput = 0;

	shellname = argv[0];
	while (1)
	{
		/* Print the prompt in terminal */
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		/* when the user press ctrl+c */
		signal(SIGINT, signalctrl_c);
		/* read the user input */
		userInput = getline(&buf, &sizebuf, stdin);
		/* In error "\n" and ends the program*/
		if (userInput == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (userInput == EOF)
		{
			break;
		}
		/* changes the '\n' from the buf to '\0' */
		if (buf[userInput - 1] == '\n')
			buf[userInput - 1] = '\0';
		/* If the user does not write anything and only press enter */
		if (*buf == '\0')
			continue;
		/* If the user types "exit" */
		if (tokenize_cmd(buf, env) == 2)
			break;
	}
	/* Frees the buf memory and returns the value of the beginning  */
	free(buf);
	fflush(stdin);
	buf = NULL;
	return (0);
}

/**
 *tokenize_cmd - tokenizes each command entered by the user.
 *@buf: command entered by the user.
 *@env: pointer to the enviroment list.
 *Return: the enviroment if the user types "env", the execution of the command,
 *or 2 if the user types exit (this ends the program).
 */
int tokenize_cmd(char *buf, char **env)
{
	char *token;
	char *array[100];
	int i = 0;

	/* If the user types exit, return 2 (this is in the main) */
	if (_strcmp(buf, "exit", 4) == 0)
		return (2);
	/* If the user types "env" return the _printenv function */
	if (_strcmp(buf, "env", 3) == 0)
		return (_printenv(env));
	/* tokenizes the buf and sends it to the execution process */
	token = strtok(buf, DELIM);
	while (token)
	{
		array[i++] = token;
		token = strtok(NULL, DELIM);
	}
	array[i] = NULL;
	/* if cmd = " " (spaces) */
	if (array[0] == NULL)
	{
		return (0);
	}
	return (_execute(array));
}

/**
 *_execute - executes the command stored in the array.
 *@array: array of the commands.
 *Return: 0, or 1 in exit.
 */

int _execute(char *array[])
{
	char *exec_path = NULL;
	char *cmd = NULL;
	pid_t pid;
	int status;

	cmd = array[0];
	/* search the cmd in the env and send it to the exec_path  */
	exec_path = searchpath(cmd, environ);
	/* If the command was not found, executes the not_path function */
	if (exec_path == NULL)
	{
		not_path(cmd);
		return (0);
	}
	/* fork process to create a child to run the program */
	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (pid > 0)
	{
		wait(&status);
	}
	/* the child executes the program and perror returns only on error */
	else if (pid == 0)
	{
		execve(exec_path, array, environ);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	/* frees the exec_path */
	free(exec_path);
	return (0);
}

/**
 *not_path - Prints in case the command is not found..
 *@cmd: the command entered by the user.
 *Return: 0.
 */
void not_path(char *cmd)
{
	/* function to write on error */
	write(STDOUT_FILENO, shellname, _strlen(shellname));
	write(STDOUT_FILENO, ": 1: ", 5);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, ": not found\n", 12);
}
