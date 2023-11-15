#include "simple_shell_kd.h"

extern char **environ;
/**
 * kd_env - Our env function
 * Return: void
*/
void kd_env(void)
{
	char **kd_our_env = environ;

	while (*kd_our_env != NULL)
	{
		kd_print(*kd_our_env);
		kd_our_env++;
	}
}
