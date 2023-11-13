#include "simple_shell_kd.h"
/**
 * kd_handle_path - function that executes commands and handles path
 * @textprint: input parameter
 * Return: none
 */
void kd_handle_path(char *textprint)
{
	pid_t new_pid = fork();

	if (new_pid == -1)
	{
		perror("fork error occurred");
		exit(EXIT_FAILURE);
	} else if (new_pid == 0)
	{
		char *argv[(MAX_CMD_LEN / 2) + 1];
		int argc = 0;
		char *kd_dir;
		char *kd_token = strtok(textprint, " ");
		/* Confirm whether the command exists in the PATH */
		char *kd_path = getenv("PATH");
		char kd_path_copy[MAX_CMD_LEN];
		strcpy(kd_path_copy, kd_path);

		/* Tokenize the copy of kd_path, i.e kd_path_copy */
		kd_dir = strtok(kd_path_copy, ":");

		while (kd_dir != NULL)
		{
			char kd_cmd_exec[MAX_CMD_LEN];
			char *temp_buffer;

			size_t temp_buffer_size = snprintf(NULL, 0, "%s/%s", kd_dir, kd_cmd_exec) + 1;
			temp_buffer = malloc(temp_buffer_size);

			snprintf(temp_buffer, temp_buffer_size, "%s/%s", kd_dir, kd_cmd_exec);
			snprintf(kd_cmd_exec, sizeof(kd_cmd_exec), "%s", temp_buffer);

			/* Confirm that it's executable */
			if (access(kd_cmd_exec, X_OK) == 0)
			{
				char *kd_args[2];
				kd_args[0] = textprint;
				kd_args[1] = NULL;
				execve(kd_cmd_exec, kd_args, NULL);
				perror("An error has occurred");
				exit(EXIT_FAILURE);
			}
			free(temp_buffer);
		}

		/* Tokenize input into arguments */
		/* Split the text by space */
		
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
