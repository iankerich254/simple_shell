#include "simple_shell_kd.h"
/**
 * main - entry to the program
 * Return: 0 on success
 */
int main(void)
{
	char textprint[MAX_CMD_LEN];

	while (true)
	{
		kd_prompt();
		kd_read_command(textprint, MAX_CMD_LEN);
		kd_execute_command(textprint);
		kd_print(textprint);
	}
	return (0);
}

