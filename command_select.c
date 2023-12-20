#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/**
 * get_command - fetch the command passed, if it is valid
 * @op: the command to be returned
 * @count: the current line number of the file, for error handling
 *
 * Return: the requested command, if valid
*/
void (*get_command(char *op, unsigned int count))(stack_t **, unsigned int)
{
	int i = 0;
	int comparison;
	instruction_t list[] = {
		{"pall", pall_m},
		{"pint", pint_m},
		{"pop", pop_m},
		{"swap", swap_m},
		{"add", add_m},
		{"nop", nop},
		{NULL, NULL}
	};

	while (i < 6)
	{
		comparison = strcmp(op, list[i].opcode);
		if (comparison == 0)
			return (list[i].f);
		i++;
	}
	null_command(op, count);
	exit(EXIT_FAILURE);
}
