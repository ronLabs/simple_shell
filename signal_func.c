#include "shell.h"

/**
 *signalctrl_c - shell should not quit when the user inputs ^C
 *@signal: unused.
 *Return: 0. Just newline and new prompt.
 */

void signalctrl_c(int signal)
{
	(void)signal;

	write(STDOUT_FILENO, "\n$ ", 3);
}
