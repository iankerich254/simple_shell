#ifndef SIMPLE_SHELL_KD
#define SIMPLE_SHELL_KD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_CMD_LEN 255

void kd_print(const char *textprint);
void kd_prompt(void);
void kd_read_command(char *textprint, size_t size);
void kd_execute_command(char *textprint);

#endif
