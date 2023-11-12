#include "simple_shell_kd.h"
/**
 * kd_execute_command - function that executes commands
 * @textprint: input parameter
 * Return: none
 */
void kd_execute_command(char *textprint)
{
	pid_t new_pid = fork();

	if (new_pid == -1)
	{
		perror("fork error occurred");
		exit(EXIT_FAILURE);
	} else if (new_pid == 0)
	{
		/* Tokenize input into arguments */
		char *argv[(MAX_CMD_LEN / 2) + 1];
		int argc = 0;
		/* Split the text by space */
		char *kd_token = strtok(textprint, " ");

		while (kd_token != NULL)
		{
			argv[argc] = kd_token;
			kd_token = strtok(NULL, " ");
			argc++;
		}
		/* The argument list is terminated with NULL */
		argv[argc] = NULL;
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Execve error occurred");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(NULL);
	}
}

