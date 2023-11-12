#include "simple_shell_kd.h"
/**
 * kd_read_command - this is a function that receives user input
 * @textprint: the command read
 * @size: size of the command
 * Return: none
 */
void kd_read_command(char *textprint, size_t size)
{
	if (fgets(textprint, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			kd_print("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			kd_print("An error has occurred when reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	textprint[strcspn(textprint, "\n")] = '\0';
}

