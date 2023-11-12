#include "simple_shell_kd.h"

/**
 * kd_print - our simple shell print function
 * @textprint: input text to be printed
 * Return: none
 */
void kd_print(const char *textprint)
{
	write(STDOUT_FILENO, textprint, strlen(textprint));
}

